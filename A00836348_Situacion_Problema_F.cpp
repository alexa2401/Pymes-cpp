#include <iostream>
#include <cstdlib>

using namespace std;

class DatGeneral{
    private:
        string nom, direccion, rS;

    public:
        DatGeneral(string, string, string);

        void mostrar_datGeneral();

        void registrar_datGeneral();

        string darNom();
};

class Pyme : public DatGeneral{

    private:
    
        string director;
        int empleados;
        double ingresos;

    public:
        Pyme(string, string, string, string, int, double);

        void mostrarPyme();
        
        void registrarPyme();

        string darNombre();

};

class Empleado : public DatGeneral{
    private:
        string nombre, puesto;
        int edad;
        double sueldo;
    public:
        Empleado(string, string, string, string, string, int, double);

        void mostrarEmpleado();
        void registrarEmpleado();
};


DatGeneral::DatGeneral(string _nom, string _direccion, string _rS){

    nom = _nom;
    direccion = _direccion;
    rS = _rS;

}

Pyme::Pyme(string _nom, string _direccion,  string _rS, string _director, int _empleados, double _ingresos) : DatGeneral(_nom, _direccion, _rS){
    director = _director;
    empleados = _empleados;
    ingresos = _ingresos;
}

Empleado::Empleado(string _nom, string _direccion, string _rS, string _nombre, string _puesto, int _edad, double _sueldo) : DatGeneral(_nom, _direccion, _rS){

    nombre = _nombre;
    puesto = _puesto;
    edad = _edad;
    sueldo = _sueldo;

}

void DatGeneral::mostrar_datGeneral(){

    cout<<"------------------------------------------------------"<<endl;

    cout<<"El nombre de la empresa es: "<<nom<<endl;
    cout<<"La direccion de la empresa es: "<<direccion<<endl;
    cout<<"La razon social de la empresa es: "<<rS<<endl;

}

void DatGeneral::registrar_datGeneral(){

    string desechable;
    
    cout<<""<<endl;
    getline(cin, desechable);

    cout<<"Introduce el nombre de la empresa: "<<endl;
    getline(cin, nom);

    cout<<"Introduce la direccion de la empresa: "<<endl;
    getline(cin, direccion);

    cout<<"Introduce la razon social de la empresa: "<<endl;
    getline(cin, rS);

}

string DatGeneral::darNom(){
    return nom;
}

void Pyme::mostrarPyme(){
    mostrar_datGeneral();
    cout<<"El nombre del director de la empresa es: "<<director<<endl;
    cout<<"El numero de empleados es: "<<empleados<<endl;
    cout<<"Los ingresos son: $"<<ingresos<<endl;
}

void Pyme::registrarPyme(){

    registrar_datGeneral();

    cout<<"Introduce el nombre del director de la empresa: "<<endl;
    getline(cin, director);

    cout<<"Introduce el numero de empleados: "<<endl;
    cin>>empleados;

    cout<<"Introduce los ingresos: "<<endl;
    cin>>ingresos;

    mostrarPyme();
}

string Pyme::darNombre(){
    string nomPyme;

    nomPyme = darNom();

    return nomPyme;

}

void Empleado::mostrarEmpleado(){
    mostrar_datGeneral();
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Puesto: "<<puesto<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"Sueldo: $"<<sueldo<<endl;
}

void Empleado::registrarEmpleado(){

    registrar_datGeneral();

    cout<<"Introduce el nombre: "<<endl;
    getline(cin, nombre);

    cout<<"Introduce el puesto: "<<endl;
    getline(cin, puesto);

    cout<<"Introduce la edad: "<<endl;
    cin>>edad;

    cout<<"Introduce el sueldo: "<<endl;
    cin>>sueldo;
}

int main(){

    int tamano = 3;

    Pyme lista_pymes[3] = {Pyme("Espacio Vacio", "Paseo del panorama", "Moral", "Garza Sada", 22, 3400), 
    Pyme("Espacio Vacio", "Paseo del panorama", "Moral", "Garza Sada", 22, 3400), 
    Pyme("Espacio Vacio", "Paseo del panorama", "Moral", "Garza Sada", 22, 3400)} ;

    Empleado lista_empleados[10] = {Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500),
    Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500),
    Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500),
    Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500),
    Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500),
    Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500),
    Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500),
    Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500),
    Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500),
    Empleado("Tec", "Paseo del panorama", "moral", "Juan Perez", "Mecanico", 22, 4500)};
    
    


    int op = 0;
    int op2 = 0;
    int i = 0;

    string nombrePyme;

    

    //Pyme pyme1("Tec", "Paseo del panorama", "Moral", "Garza Sada", 22, 3400);
    //Empleado empleado1("Tec", "Paseo del panorama", "Moral", "Alejandro", "Jefe", 18, 4000);



    while(true){

        cout<<"------------------------------------------------------"<<endl;

        cout<<"Selecciona el numero de la opcion deseada: "<<endl;
        cout<<"1 - Agregar Pyme"<<endl;
        cout<<"2 - Agregar empleado"<<endl;
        cout<<"3 - Consultar Pyme"<<endl;
        cout<<"4 - Consultar trabajador"<<endl;
        cout<<"5 - Cerrar"<<endl;

        cin>>op;

        switch (op)
        {
        case 1:

            cout<<"------------------------------------------------------"<<endl;


            lista_pymes[i].registrarPyme();
            nombrePyme = lista_pymes[i].darNombre();
            i++;
            cout<<"el nombre de esta empresa es: "<<nombrePyme<<endl;
            break;

        case 2: 

            cout<<"------------------------------------------------------"<<endl;

            cout<<"opcion 2"<<endl;
            for (int n = 0; n < tamano; n++)
            {
                cout<<n+1<<" - "<<lista_pymes[n].darNombre()<<endl;
            }
            
            cout<<"Escribe el numero de la pyme donde quieres añadir al trabajador: "<<endl;
            cin>>op2;
            switch (op2)
            {
            case 1:
                op2 = op2-1;


                
                break;

            case 2:
                op2 = op2-1;

                break;

            case 3:
                op2 = op2-1;

                break;
            
            default:
                cout<<"Este numero no es válido"<<endl;
                break;
            }
            break;

        case 3: 
            cout<<"------------------------------------------------------"<<endl;
            cout<<"Las Pymes registradas son: "<<endl;

            for (int n = 0; n < tamano; n++)
            {
                cout<<n+1<<" - "<<lista_pymes[n].darNombre()<<endl;
            }
            
            cout<<"Escribe el numero de la pyme que quieres consultar: "<<endl;
            cin>>op2;
            switch (op2)
            {
            case 1:
                op2 = op2-1;
                lista_pymes[op2].mostrarPyme();
                
                break;

            case 2:
                op2 = op2-1;
                lista_pymes[op2].mostrarPyme();

                break;

            case 3:
                op2 = op2-1;
                lista_pymes[op2].mostrarPyme();

                break;
            
            default:
                cout<<"Este numero no es válido"<<endl;
                break;
            }

            break;

        case 4: 
            cout<<"opcion 4"<<endl;
            break;

        case 5:
            //cout<<"opcion 5"<<endl;
            exit(1);
            break;
        
        default:
            cout<<"Has elegido una opcion no valida. Intenta de nuevo"<<endl;
            break;
        }
    }


    return 0;
}
