#include <iostream>
#include <fstream>
#include <format>
#include <vector>
class Node
{
    public:
    Node()
    :x{0},y{0}
    {}

    Node(double mx,double my)
    :x{mx},y{my}
    {}


    double x;
    double y;
};
class QuadElement
{
    public:
    QuadElement()
    :a{0},b{0},c{0},d{0}
    {}
    QuadElement(int aa,int bb,int cc,int dd)
    :a{aa},b{bb},c{cc},d{dd}
    {}

    friend std::ostream& operator<<(std::ostream& os, const QuadElement& element);
    
    
    int a;
    int b;
    int c;
    int d;
};
std::ostream& operator<<(std::ostream& os, const QuadElement& element)
{
    os << element.a<<" "<<element.b<<" "<<element.c<<" "<<element.d <<'\n';
    return os;
}
int main()
{
    std::cout<<"Enter square dimensions and element width"<<std::endl;
    double sqLength{},elementLength{};
    std::cin>>sqLength>>elementLength;
    std::cout<< std::format("Square dimensions is {} and element size is {} ",sqLength,elementLength)<<std::endl;

    const int count  = sqLength/elementLength;
    const int numberOfElements = count*count;
    const int numberOfNodes = (count+1)*(count+1);

    

    std::vector<Node> nodeArray;
    nodeArray.reserve(numberOfNodes);
    std::vector<QuadElement> elementArray;
    elementArray.reserve(numberOfElements);
    
    for (size_t i{}; i <= count ; i++)
    {
        /* code */
        for (size_t j{}; j <= count ; j++)
        {
            /* code */
            //create element and store in the respective database
            double x1 = i * elementLength;
            double y1 = j * elementLength;

            nodeArray.emplace_back(x1,y1);
        }
        
    }

    for (size_t i{}; i < count ; i++)
    {
        /* code */
        for (size_t j{}; j < count ; j++)
        {
            int node1 = i*(count+1)+j+1;
            int node2 = node1+count+1;
            elementArray.emplace_back(node1,node2,node2+1,node1+1);
        }
        
    }

    // int nodeCounter2{},elementCounter2{};
    
    std::ofstream file;
    file.open("../pyara.tec");
    // TITLE = "title"
    // VARIABLES  = "X", "Y"
    // ZONE NODES=36, ELEMENTS=25, ZONETYPE=FEQUADRILATERAL, DATAPACKING=BLOCK
    file<<"TITLE = \"title\"\n";
    file<<"VARIABLES  = X, Y\n";
    file<<"ZONE  NODES="<<numberOfNodes<<", ELEMENTS="<<numberOfElements<<
    ", ZONETYPE=FEQUADRILATERAL, DATAPACKING=BLOCK\n";

    int newlineCounter{};
    for(auto &mNode:nodeArray)
    {
        if(newlineCounter % 10 == 0)
            file<<'\n';
        /* code */
        file<<mNode.x<<" ";
        newlineCounter++;
    }
    file<<'\n';
    newlineCounter = 0;
    for(auto &mNode:nodeArray)
    {
        if(newlineCounter % 10 == 0)
            file<<'\n';
        /* code */
        file<<mNode.y<<" ";
        newlineCounter++;
    }
    file<<'\n';
    
    
    
    for(auto &mElement:elementArray)
    {
        file<<mElement;
    }
    file.close();
    std::cout<<"SUCESSFULL"<<std::endl;
    
    


}
