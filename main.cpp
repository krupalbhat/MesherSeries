#include <iostream>
#include <fstream>
#include <format>
#include <vector>
class Node
{
    public:
    Node()
    :x{0},y{0},z{0}
    {}

    Node(double mx,double my,double mz)
    :x{mx},y{my},z{mz}
    {}

    Node(const Node& mNode)
    :x{mNode.x},y{mNode.y},z{mNode.z}
    {}

    Node& operator= (const Node& mNode)
    {
        // self-assignment guard
        if (this == &mNode)
            return *this;

        // do the copy
        this->x = mNode.x;
        this->y = mNode.y;
        this->z = mNode.z;
        

        // return the existing object so we can chain this operator
        return *this;
    }

    void setCoordinates(double mx,double my,double mz)
    {
        x = mx;
        y = my;
        z = mz;
    }

private:
    double x;
    double y;
    double z;
};
class Element
{
    public:
    Element(int m_elementType)
    :elementType{m_elementType}
    {
        
    }
    
    static constexpr int POINT = 1;
    static constexpr int LINE  = 2;
    static constexpr int TRIANGLE = 3;
    static constexpr int QUAD = 4;
    static constexpr int TETRAHEDRON = 5;
    static constexpr int PYRAMID = 6;
    static constexpr int WEDGE = 7;
    static constexpr int HEXAHEDRON = 8;

    
    // friend std::ostream& operator<<(std::ostream& os, const Element& element);

    private:
    int elementType;
    std::vector<int> nodeConnectivity;
};
// std::ostream& operator<<(std::ostream& os, const Element& element)
// {
//     os << element.a<<" "<<element.b<<" "<<element.c<<" "<<element.d <<'\n';
//     return os;
// }
int main()
{
    // std::cout<<"Enter square dimensions and element width"<<std::endl;
    // double sqLength{},elementLength{};
    // std::cin>>sqLength>>elementLength;
    // std::cout<< std::format("Square dimensions is {} and element size is {} ",sqLength,elementLength)<<std::endl;

    // const int count  = sqLength/elementLength;
    // const int numberOfElements = count*count;
    // const int numberOfNodes = (count+1)*(count+1);

    

    // std::vector<Node> nodeArray;
    // nodeArray.reserve(numberOfNodes);
    // std::vector<QuadElement> elementArray;
    // elementArray.reserve(numberOfElements);
    
    // for (size_t i{}; i <= count ; i++)
    // {
    //     /* code */
    //     for (size_t j{}; j <= count ; j++)
    //     {
    //         /* code */
    //         //create element and store in the respective database
    //         double x1 = i * elementLength;
    //         double y1 = j * elementLength;

    //         nodeArray.emplace_back(x1,y1);
    //     }
        
    // }

    // for (size_t i{}; i < count ; i++)
    // {
    //     /* code */
    //     for (size_t j{}; j < count ; j++)
    //     {
    //         int node1 = i*(count+1)+j+1;
    //         int node2 = node1+count+1;
    //         elementArray.emplace_back(node1,node2,node2+1,node1+1);
    //     }
        
    // }

    // // int nodeCounter2{},elementCounter2{};
    
    // std::ofstream file;
    // file.open("../pyara.tec");
    // // TITLE = "title"
    // // VARIABLES  = "X", "Y"
    // // ZONE NODES=36, ELEMENTS=25, ZONETYPE=FEQUADRILATERAL, DATAPACKING=BLOCK
    // file<<"TITLE = \"title\"\n";
    // file<<"VARIABLES  = X, Y\n";
    // file<<"ZONE  NODES="<<numberOfNodes<<", ELEMENTS="<<numberOfElements<<
    // ", ZONETYPE=FEQUADRILATERAL, DATAPACKING=BLOCK\n";

    // int newlineCounter{};
    // for(auto &mNode:nodeArray)
    // {
    //     if(newlineCounter % 10 == 0)
    //         file<<'\n';
    //     /* code */
    //     file<<mNode.x<<" ";
    //     newlineCounter++;
    // }
    // file<<'\n';
    // newlineCounter = 0;
    // for(auto &mNode:nodeArray)
    // {
    //     if(newlineCounter % 10 == 0)
    //         file<<'\n';
    //     /* code */
    //     file<<mNode.y<<" ";
    //     newlineCounter++;
    // }
    // file<<'\n';
    
    
    
    // for(auto &mElement:elementArray)
    // {
    //     file<<mElement;
    // }
    // file.close();
    // std::cout<<"SUCESSFULL"<<std::endl;
    
    


}
