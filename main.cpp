#include <iostream>
#include <vector>

using namespace std;

class Graph{
public:

    class Vertex{
        public:
            int id;
            vector <Vertex*> neighbours;

            Vertex(int id){
                this->id=id;
            }
    };

    vector<Vertex*> vertices;

    void insertVertex(int id){
        if(!this->findVertex(id)){
        this->vertices.push_back(new Vertex(id));
        }

    }

    void insertVertex(int id, vector<int> neighboursId){
        Vertex* newVertex=this->findVertex(id);
if(!newVertex){

    newVertex=new Vertex(id);
        this->vertices.push_back(newVertex);
}
for(auto neighbourId:neighboursId){
    Vertex* neighbour=findVertex(neighbourId);
    if(neighbour!=nullptr){
        newVertex->neighbours.push_back(neighbour);
        if(newVertex!=neighbour){
        neighbour->neighbours.push_back(newVertex);
        }
    }
}

        
    }

    Vertex* findVertex(int id){
        for(auto vertex:vertices){
            if(vertex->id==id){
                return vertex;
            }
        }
        return nullptr;
    }

};


int main(){
    Graph g;

    vector<int> neighbours;

     for (int i = 1; i <= 10; ++i) {
        g.insertVertex(i);
    }
    g.insertVertex(1, {2,3});
    g.insertVertex(2, {3, 4});
    g.insertVertex(5, {6, 7, 8});
    g.insertVertex(8, {9, 10});
    g.insertVertex(3,{5});

    // Выводим информацию о соседях для каждой вершины
    for (auto vertex : g.vertices) {
        cout << "Vertex " << vertex->id << " has neighbours: ";
        for (auto neighbour : vertex->neighbours) {
            cout << neighbour->id << " ";
        }
        cout << endl;
    }



    return 0;
}