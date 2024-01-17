# GraphMaker

## Jak pisać w c++

Kilka porad do c++. Proszę przeczytać!


### Klasy i dziedziczenie

Tworzenie klas i implementacje:

```c++
// plik.h
class A
{
    int x; // Bazowo prywatne

private: // od tego momentu elementy prywatne
    int y;

    void private_fun(); // deklaracja funkcji do inplementacji
    void private_fun(int a); // przeciążanie funkcji


public: // od tego momentu elementy publiczne

    A() : x(0), y(0){} // Konstruktor bezparametrowy + lista inicjalizacyjna
    A(int x, int y) : x(x), y(y){} // Konstruktor parametrowy
    A(int x): x(x), y(0){} // Inny konstruktor parametrowy
    A(int y): x(0) // Dlaczego lista inicjalizacyjna jest ważna?
    {
        // Teraz x=0, y=śmieci (NIE RÓWNE NULL)
        y = 0; 
        // Teraz x=0, y=0
    }

private: // Ponownie prywatne
    
    void private_fun(int a) // Późniejsza implementacja w .h
    {
        std::cout<<"Obiekt wypisuje "<<a<<std::endl;
    }
    
public:
    
    void const_fun() const; // Funkcja gwarantuje niezmienność obiektu
    void noexcept_fun() noexcept; // Funkcja gwarantuje niepojawienie się wyjątków.
    
    class B // Przykład klasy wewnętrznej
    {
        private:
            int x;
        public:
            friend class A; // Teraz klasa A ma dostęp do prywatnych elementów klasy B
    }
    
    int get_x_from_B(B b);  // Przekazywanie przez kopie (nowa instancja zostanie stworzona przy wywołaniu funkcji)
    int get_x_from_B(B& b); // Przekazywanie przez referencje (do funkcji przekazano orginał)
    int get_x_from_B(B* b); // Przekazywanie przez wskaźnik (jak w c)
    
    friend class C; // Teraz klasa C ma dostęp do prywatnych elementów klasy A (mimo że może nie istnieć jeszcze)

}

// plik.cpp

void A::private_fun() // Implementacja funkcji klasy A
{
    std::cout<<"Obiekt mowi hello!<<std::endl;
}

int A::get_x_from_B(A::B& b) // Wykoarzystanie klasy wewnętrznej poza deklaracją
{
    return b.x; // Odwołanie jest takie same jak przy kopii a nie jak przy wskaźniku.
}

void fun() // Przykłady inicjacji obiektów
{
    A a1; // Element zainicjowany natychmiast konstruktorem oznaczonym default (w tym wypadku bezparametrowy).
    A* a2 = new A(1, 2); // Zamiast malloca + wywołanie konkretnego konstruktora.
    A::B b1; // Klasa wewnętrzna.
    delete a2; // Zamiast free.
    A a3(1,2); // BŁĄD KOMPILACJI!!!
}

```

Klasy abstrakcyjne i dziedziczenie:

```c++

class C
{
protected: // Widoczne przez dziedziczone
    int x;
    
public:
    virtual void abst_fun() = 0; // Metoda abstrakcyjna (od tego momentu klasa jest też abstrakcyjna)
    
    virtual void virtual_fun()
    {
        std::cout<<"Tu klasa bazowa z funkcji wirtualnej!"<<std::endl;
    }
    
    void normal_fun()
    {
        std::cout<<"Tu klasa bazowa z funkcji normalnej!"<<std::endl;
    }
}


class D : public C // Dzidziczenie po C
{
public:
    
    virtual void abst_fun() // Implementacja metody abstrakcyjnej
    {
        std::cout<<"Tu klasa pochodna z funkcji abstrakcyjnej!"<<std::endl;
    }

    virtual void virtual_fun()
    {
        std::cout<<"Tu klasa pochodna z funkcji wirtualnej!"<<std::endl;
    }
    
    void normal_fun()
    {
        std::cout<<"Tu klasa pochodna z funkcji normalnej!"<<std::endl;
    }
    
    virtual void new_fun()
    {
        C::virtual_fun(); // Korzystanie z klasy bazowej.
    }
}


void fun()
{
    D* ptr_d = new D(); // obiekt D wewnątrz pointera D
    C* ptr_c = ptr_d;   // obiekt D wewnątrz pointera C
    
    // WAŻNOŚĆ SŁOWA VIRTUAL!!!
    
    ptr_d->virtual_fun();   // Wypisano: "Tu klasa pochodna z funkcji wirtualnej!"
    ptr_d->normal_fun();    // Wypisano: "Tu klasa pochodna z funkcji normalnej!"
    
    ptr_c->virtual_fun();   // Wypisano: "Tu klasa pochodna z funkcji wirtualnej!"
    ptr_c->normal_fun();    // Wypisano: "Tu klasa bazowa z funkcji normalnej!"
}

```

Pozostałe ciekawe informacje:

- Konstruktor kopiujący a przenoszący: https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/


### Shared pointery

Pisząc programy w c++ staramy się używać shared pointerów pilnujących za nas pamięć.
```c++
#include<memory> // Załączenie shared pointerów

class A
{
    int x;
    int y;
    
    A(int x, int y): x(x), y(y){}
public:
    A(int x): x(x), y(0){}
    
    int get_x(){return x;}
    
    friend class B;
}

void fun()
{
    std::shared_ptr<A> a = std::make_shared<A>(1) // Tworzenie shared pointera (tylko gdy konstruktor publiczny).
    std::cout<<a->get_x()<<std::endl; // Użycie jak zwykłego pointera.
}

class B
{
public:
    static std::shared_ptr<A> init_A(int x, int y)
    {
        return std::shared_ptr<A>(new A(x, y)); // Tworzenie shared pointera (można publiczy i prywatny).
    }
}

void fun2()
{
    std::shared_ptr<A> a = B::init_A(1,2); // Przykład użycia statycznej metody.
}

```

UWAGA na zapętlanie shared pointerów! 

```c++

class C
{
public:
    std::shared_ptr<C> ptr;
}

void fun()
{
    std::shared_ptr<C> c = std::make_shared<C>();
    c->ptr = c; // Po wyjściu z funkcji wyciek pamięci.
}

```


### Wyjątki

Implementacja własnego wyjątku:
```c++
class my_exception : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Raised my exception";
    }
};

```

Podział metod ze względu na wyjątki:

- noexcept: Funkcja nigdy nie zgłosi wyjątku (próba zgłoszenia zakończy się terminacją programu i errorem).
- strong: Po zgłoszeniu wyjątku obiekt pozostaje niezmienny w porównaniu do tego, jaki był przed wywołaniem metody.
- weak: Po zgłoszeniu wyjątku obiekt jest stabilny (choć wewnętrzne elementy mogły się zmienić)

Krzyżówki metod:

- noexcept + noexcept = noexcept (Nie ma możliwości zgłoszenia wyjątku)
- strong + noexcept = strong (Wyjątek może być zgłoszony tylko przez pierwszą metodę)
- noexcept + strong = weak (Po zgłoszeniu wyjątku pierwsza metoda mogła coś zmienić w obiekcie)
- strong + strong = weak (Jak wyżej)

Co nie zgłasza wyjątków:

- Destruktor (raczej)
- Operacje na iteratorach
- Operacje na wskaźnikach
- remove (wykorzystując iterator)

Sposoby radzenia z wyjątkami:

- Tworzenie kopii na start funkcji (problem: O(n) czasowo plus dodatkowa pamięć)
- Cofanie zmian (problem: należy korzystać z noexcept metod żeby jeszcze raz nie wywołać wyjątku)

Przykład radzenia z wyjątkiem:

```c++
class A
{
    std::set<int> s1;
    std::set<int> s2;
public:
    void add(int x)
    {
        auto it = s1.insert(x).first; // auto = typ uniwersalny; insert zwraca parę<iterator, bool>
        try{
            s2.insert(x); // Może zgłosić wyjątek po zmianie w s1
        }
        catch(exception e) // Wyjątek zgłoszony?
        {
            s1.remove(it); // Usuwanie zmian iteratorem jest noexcept
            throw e;    // Gwarancja przezroczystości na wyjątki
        }
    }
    return; // Nie było wyjątku to kończymy
};
```


## Wskazówki do konkretnych klas

Żeby nie zapomieć się piszę podpowiedzi którymi warto się kierować:

### graph_decorator

- Pamiętać o słówku virtual przy odpowiednich funkcjach
- is_valid() sprawdza swój warunek i jak jest ok to zwraca wynik funkcji u dekorowanego
- Graf trzymać w shared_ptr
- Pamiętać o prywatnym konstruktorze i usunięciu niepotrzebnych
- Przygotować friend dla fabryki
- acykliczny i dodatni mają zwrócić wyjątek jeżeli nie są spełnione warunki
- spojny nie musi być valid

### command

- Należy trzymać iteratory do stworzonych przez nie elementów
- Przyda się dodać jakieś zmienne kreacyjne (np id do wierzchołków)
- add() musi być strong
- undo() musi być noexcept

### factory

- Wykonuje konstruktor prywatny swojego dekoratora
- Zwraca shared_ptr stworzonego obiektu
- Przezroczysty na wyjątki
- Kostruktory muszą być prywatne
- Musi istnieć singleton do którego dostęp jest przez funkcję get_instance()

### builder

- Jest friendem graph
- Konstruktor jest prywatny
- Fasada ma być friendem budowniczego
- Budowniczych może być wiele
- Graf trzymany w zmiennej musi być shared_ptr
- Commandy są trzymane w shared_ptr na stosie (std::stack)
- Przezroczysty na wyjątki
- undo() zwraca wyjątek jeżeli nie ma co cofać (stos pusty)
- Każda funkcja ma być strong
- build() ma sprawdzić is_valid() i w razie czego zwrócić wyjątek

### facade

- Jest friendem budowniczego i on tworzy jego instancje jako shared_ptr (w pewnym sensie jest fabryką)
- Algorytmy trzymane i przyjmowane są w shared_ptr
- Grafy przyjmowane są jako shared_ptr
- Należy przygotować się, że execute strategi bedzie zwracać jakąś instancję (mockupem może być void)


### strategy

- Nie jest friendem grafu
- Należy korzystać z iteratorów do przeglądania grafu
- Należy przemyśleć instancje zwracane jako rezultaty algorytmów
- Są singletonami (prywatny konstruktor + get_instance())


