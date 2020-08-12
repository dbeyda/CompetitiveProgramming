/* Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
that type). They cannot select which specific animal they would like. Create the data structures to
maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
and dequeueCat. You may use the built-in Linked List data structure.
*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Animal
{
    int m_Id;
    string m_Name;
public:
    Animal(const char *name) { m_Name = name; }
    void setId(int id) { m_Id = id; }
    int getId() { return m_Id; }
    string getName() { return m_Name; }
    virtual void print() = 0;
};

class Dog: public Animal {
    public:
    Dog(const char* name) : Animal(name) {};
    void print() { cout << "<Dog> " << getName() << '\n'; };
};
class Cat: public Animal {
    public:
    Cat(const char* name) : Animal(name) {};
    void print() { cout << "<Cat> " << getName() << '\n'; };
};

class ShelterQueue
{
    list<Dog*> m_DogQ;
    list<Cat*> m_CatQ;
    int m_NextId = 1;

public:
    void push(Dog *newAnimal)
    {
        newAnimal->setId(m_NextId);
        m_DogQ.push_back(newAnimal);
        m_NextId++;
    }

    void push(Cat *newAnimal)
    {
        newAnimal->setId(m_NextId);
        m_CatQ.push_back(newAnimal);
        m_NextId++;
    }

    Dog* getDog()
    {
        Dog *a = m_DogQ.front();
        m_DogQ.pop_front();
        return a;
    }

    Cat* getCat()
    {
        Cat *a = m_CatQ.front();
        m_CatQ.pop_front();
        return a;
    }

    Animal* getNext()
    {
        if (m_DogQ.empty() && m_CatQ.empty())
        {
            cout << "No animals currently available =(. Try again next week.\n";
            exit(1);
        }
        if (m_DogQ.empty()) return getCat();
        if (m_CatQ.empty()) return getDog();

        if(m_DogQ.front()->getId() < m_CatQ.front()->getId())
            return getDog();
        else
            return getCat();
    }
};

int main()
{
    ShelterQueue q;

    list<Dog> vDog;
    list<Cat> vCat;


    vDog.push_back(Dog("Cao marcos"));
    q.push(&vDog.back());
    cout << "Pegando o bicho ";
    q.getNext()->print();

    vCat.push_back(Cat("Cat catino"));
    q.push(&vCat.back());
    vCat.push_back(Cat("Cat velho"));
    q.push(&vCat.back());
    vDog.push_back(Dog("Cão novo"));
    q.push(&vDog.back());

    cout << "Pegando o bicho ";
    q.getNext()->print();
    cout << "Pegando o bicho ";
    q.getNext()->print();
    cout << "Pegando o bicho ";
    q.getNext()->print();

    vDog.push_back(Dog("Cão 1"));
    q.push(&vDog.back());
    vDog.push_back(Dog("Cão 2"));
    q.push(&vDog.back());
    vCat.push_back(Cat("Cat 1"));
    q.push(&vCat.back());
    vDog.push_back(Dog("Dog 3"));
    q.push(&vDog.back());

    cout << "Pegando o gato ";
    q.getCat()->print();
    cout << "Pegando o cao ";
    q.getDog()->print();
    cout << "Pegando o cao ";
    q.getDog()->print();
    cout << "Pegando o cao ";
    q.getDog()->print();


    return 0;
}