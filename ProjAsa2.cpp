#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<stack>
#include<unordered_map>
#include<algorithm>

using namespace std;


typedef vector<vector<int>> graph;


vector<int> readVector(uint a)
{
    uint number;
    vector<int> v;
    while(cin >> number)
    {
        if(number <= a && number > 0)
            v.push_back(number);
        if(cin.peek() == '\n' || cin.peek() == '\0')
            break;
    }
    return v;
}

vector<int> inicializesubVectorwithValue(int sizeVector,int value)
{
    vector<int> vector1;
    for(int i=0;i<sizeVector;i++)
    {
        vector1.push_back(value);
    }
    return vector1;
}

void printVector(vector<int> v1)
{
    for(uint i=0;i<v1.size();i++)
    {
        cout << v1[i] << " ";

    }
    cout << '\n';
}

bool verifymorethan3(graph familyTree,int n)
{
    int count=0;
    for(uint i=0;i<familyTree.size();i++)
    {
        if (familyTree[i][0] == n)
        {
            count++;
        }
    }
    if(count<=2)
    {
        return true;
    }
    else return false;
}

/*verificar se ha ciclos*/
graph readgraph(int vert,int a){
    graph g;
    for(int i=0;i<a;i++)
    {
        vector<int> v = readVector(vert);
        g.push_back(v);
    }
    return g;

}

void printgraph(graph g)
{
    for(uint i=0;i<g.size();i++)
    {
      printf("%d %d\n", g[i][0],g[i][1]);
    }
}

vector<int> invertVector(vector<int> v1)
{
    vector<int> v2 ;
    for(uint i=0;i<v1.size();i++)
    {
        v2.push_back(v1[v1.size()-i-1]);
    }
    return v2;
}
graph transgraph(graph g)
{
    graph invertedFamily;
    for(uint i=0;i<g.size();i++)
    {
        invertedFamily.push_back(invertVector(g[i]));
    }
    return invertedFamily;
}

int verifyFirstTerm(graph g,int vert)
{
    /*1 is true and 0 is false*/
    int state=0;
    for(uint i=0;i<g.size();i++)
    {
        if(g[i][0] == vert)
        {
            state=1;
            break;
        }
        
    }
    return state;
}

vector<int> findAdjs(graph g,int vert)
{
    vector<int> result;
    if(verifyFirstTerm(g,vert)==1)
        for(uint i=0;i<g.size();i++)
        {
            if(g[i][0] == vert)
            {
                result.push_back(g[i][1]);
            }
        }
    else
    {
        result.push_back(0);
    }

    return result;
}



unordered_map<int,bool> inicializeVisitor(int size)
{
    unordered_map<int,bool> visit;
    for(int i=1;i<=size;i++)
    {
        visit[i] = false;
    }
    return visit;
}

unordered_map<int,vector<int>> setGraph(graph g)
{
    unordered_map<int,vector<int>> settedGraph;
    for(uint i=0;i<g.size();i++)
    {
        if(g[i][0] == i+1)
        {
            settled[i+1].push_back(g[i][1]);
        }
    }
    return settedGraph;
}

void printmap(unordered_map<int,vector<int>> const &unmap)
{
    for(auto const &pair: unmap)
    {
       std::cout  << pair.first << "\n" << pair.second <<"\n"; 
    }
}



vector<sonVert> dfs(unordered_map<int,vector<int>> g,int fvert,int nVerts)
{
    unordered_map<int,bool> visited = inicializeVisitor(nVerts);
    stack<int> percorrido;
    sonVert first = findVert(registFamily,fvert);
    percorrido.push(first);
    while(!percorrido.empty())
    {
        sonVert vertice = percorrido.top();
        percorrido.pop();
        if(visited[vertice.vert] == false)
        {
            visited[vertice.vert] = true;
            if(color == "amarelo" && vertice.color == "azul")
                vertice.color = "Verde";
            else
                vertice.color = color;
            registFamily[vertice.vert].color = color;
            
        }
        for(uint i=0;i<vertice.adjs.size();i++)
        {
            if(visited[vertice.adjs[i]] == false)
            {
               sonVert adj = findVert(registFamily,vertice.adjs[i]);
               percorrido.push(adj);
            }
        }
    }
    return registFamily;
}



/*determinar os elementos da dfs dos respetivos vertices nos quais estamos a procurar os descendentes comuns mais proximos*/
/*colorir o resultado das duas bfs com cores diferentes usando a estrutura sonVerts onde vão estar os resultados*/
/*verificar elementos em comum sendo que se existe o vertise fica com a cor mistura das duas e coloca-se esses vertices num novo vetor e verifica-se em cada elemento desse vetor se têm adjacentes caso não tenha são devolvidos como resultado*/
/*Apresentar o resultado referido*/

int generationTree(matrix familyTree,int v1,int v2,int nV, int nA)
{
    for(int i=1;i<=nV;i++)
    {
        if(verifymorethan3(familyTree,i)==false)
        {
            return 0;
            break;
        }
    }
    vector<sonVert> verts = inicializeVerts(familyTree,nV);
    vector<vector<int>> transFamily = transmatrix(familyTree);
    unordered_map<int,vector<int>> familyHandler = setGraph(transFamily);
    return 1;
    


}







int main()
{

    int nV;
    int nA;
    int work = scanf("%d %d\n",&nV,&nA);
    if(work > 0)
    { 
        graph familyTree = readmatrix(nV,nA);
        graph transFamily = transmatrix(familyTree);
        unordered_map<int,vector<int>> familyHandler = setGraph(transFamily);
        printmap(familyHandler);
    }
    return 0;
}