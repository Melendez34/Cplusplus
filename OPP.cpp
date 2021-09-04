#include <iostream>

using std::string;

//abstraccion
class AbstractEmployee
{
private:
virtual void AskForPromotion() = 0;
};

class Employee:public AbstractEmployee {
protected:
  string Name;
private:
  string Company;
  int Age;

//Encapsulamiento
public:
  void setName(string name){
    Name = name;
  }
  string getName(){
    return Name;
  }

  void setCompany(string company){
    Company = company;
  }
  string getCompany(){
    return Company;
    }

  void setAge(int age){
    Age = age;
  }
  int getAge(){
    return Age;
  }

  void introduccion(){
    std::cout << "Name - " << Name << std::endl;
    std::cout << "Company - " << Company << std::endl;
    std::cout << "Age - " << Age << std::endl;
  }

  Employee(string name, string company, int age){
    Name = name;
    Company = company;
    Age = age;
  }

  void AskForPromotion(){
    if (Age > 29)
    {
      std::cout << Name <<" can be selected for promotion. " << std::endl;
    }
    else
    {
      std::cout << Name <<" keep working, no promotion. " << std::endl;
    }
  }
  // Polimorfismo
  // Podemos tener metodos que se llamen igual en cada clase y heredar de ellas sus metodos.
  // Vitual para que cada clase ejecute sus propios metodos de clase.
  // Si no existe la mismo metodo en la clase ejecutara el metodo del parent class.
  virtual void Work(){
    std::cout << Name << " is checking the email, task log, performign task..." << std::endl;
  }
};

class Developer:public Employee{

private:
  string FavPL;

public:
void setFavPL(string favPL){
    FavPL = favPL;
  }
  string getFavPL(){
    return FavPL;
  }

Developer(string name, string company, int age, string favPL)
  :Employee(name, company, age)
{
  FavPL = favPL;
}

void FixBug(){
  std::cout << getName() << " fix bug using " << getFavPL() << std::endl;
}

void Work(){
    std::cout << Name << " is writing " << getFavPL() << " Code... " <<  std::endl;
  }
};
//Herencia
class Teacher:public Employee{
public:
    string Materia;
    void PrepararClase(){

        std::cout << getName() << " " << getAge() << " " << getCompany() << std::endl;
        std::cout << Name << " esta preparando la clase de " << Materia << std::endl;
    }
public:
    Teacher(string name, string company, int age, string materia): Employee(name, company, age) {
        Materia = materia;
    }
    void Work(){
      std::cout << Name << " is teaching  " << Materia << " en lo que llaman a subir a auditorio... " <<  std::endl;
    }
};

int main()
{
    Employee employee1 = Employee("Omar", "VUBA auditorias", 31);
    Employee employee2 = Employee("Ivan", "SEARS", 24);
    Developer D1 = Developer("Omar", "Google", 29, "C++");
    Teacher T = Teacher("Panchito", "YMCA", 28, "Relleno");

    Employee *e = &D1;
    Employee *e2 = &T;

    e->Work();
    e2->Work();

}

