/*
#include <map>
#include <iostream>

namespace testmap
{


class MyMapCompare
{
public:
    bool operator()(int m,int n)
    {
        return m>n;
    }
};
int main()
{
    std::map<int,int,MyMapCompare> m;
    m.insert(std::make_pair(1,11));
    m.insert(std::make_pair(1,10));    
    m.insert(std::make_pair(2,10));
    m.insert(std::make_pair(3,9));

    for(std::map<int,int>::const_iterator it=m.begin();it!=m.end();it++)
    {
        std::cout<<"key:"<<it->first<<" val:"<<it->second<<std::endl;
    }
    return 0;
}

} //namespace testmap

*/


#include <set>
#include <iostream>


class MySetCompare
{
public:
    bool operator()(int m,int n)
    {
        return m>n;
    }
};

void printSet(std::set<int> se)
{
    for(std::set<int>::const_iterator it=se.begin();it!=se.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}
void printSet(std::set<int,MySetCompare> se)
{
    for(std::set<int,MySetCompare>::const_iterator it=se.begin();it!=se.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

}


void testset()
{
    std::set<int> s1;
    s1.insert(10);
    s1.insert(50);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    printSet(s1);

	//指定排序规则
    std::set<int,MySetCompare> s2;
    s2.insert(10);
    s2.insert(50);
    s2.insert(40);
    s2.insert(30);
    s2.insert(20);
    printSet(s2);
}

class myCompare
{
public:
    bool operator()(int m,int n)
    {
        return m>n;
    }
};




/*
int main()
{
    std::set<int> s;
    std::pair<std::set<int>::iterator,bool> ret=s.insert(10);
    if(ret.second){
        std::cout<<"first done!"<<std::endl;
    }
    else{
        std::cout<<"first failure!"<<std::endl;
    }

    ret=s.insert(10);
    if(ret.second){
        std::cout<<"second done!"<<std::endl;
    }
    else{
        std::cout<<"second failure!"<<std::endl;
    }
    for(std::multiset<int>::const_iterator it=s.begin();it!=s.end();it++)
    {
        std::cout<<*it<<std::endl;
    }



    std::multiset<int> ms;
    ms.insert(6);
    ms.insert(6);
    for(std::multiset<int>::const_iterator it=ms.begin();it!=ms.end();it++)
    {
        std::cout<<*it<<std::endl;
    }
}
*/


/*
#include <list>
#include <iostream>

void printList(const std::list<int> ll)
{
    for(std::list<int>::const_iterator it=ll.begin();it!=ll.end();it++)
    {
        std::cout<<*it<<std::endl;
    }
}

bool myCompare(int m,int n)
{
    return m>n;
}

class myCompare1
{
public:
    bool operator()(int m,int n)
    {
        return m>n;
    }
};

void testlist()
{
    std::list<int> lll;
    lll.push_back(5);
    lll.push_back(4);
    lll.push_back(8);
    lll.push_back(1);
    lll.sort();
    printList(lll);
    std::cout<<"*******"<<std::endl;
    lll.sort(myCompare);
    
    lll.sort(myCompare1());
    printList(lll);
}
*/

/*
#include <queue>
#include <vector>
#include <iostream>

struct Node
{
    int x,y;
    Node(int a=0, int b=0): x(a), y(b) {}
};


struct QueueCompatarot
{
    bool operator()(Node a, Node b)
    {
        if(a.x == b.x) return a.y>b.y;
        return a.x>b.x;
    }
};


void testPriorityQueue()
{
    std::priority_queue<Node , std::vector<Node>, QueueCompatarot> pq;
    for (size_t i = 0; i < 10; i++)
    {
        pq.push(Node(rand(),rand()));
    }

    while (!pq.empty())
    {
        std::cout<<pq.top().x<<" ";
        pq.pop();
    }
    
    
};
*/

int main()
{
    //testlist();
    //testPriorityQueue();
    testset();
}