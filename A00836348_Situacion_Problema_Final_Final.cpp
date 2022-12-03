#include <iostream>
#include <cstdlib>

using namespace std;

class Pyme{

    private:
        string nom_emp, rS, direccion, nom_dir;
        int num_emp;
        double ingresos;

    public:
        //Pyme(string, string, string, string, int, double);

        string get_nom_emp(){
            return nom_emp;
        }

        string get_rS(){
            return rS;
        }

        string get_direccion(){
            return direccion;
        }

        string get_nom_dir(){
            return nom_dir;
        }

        int get_num_emp(){
            return num_emp;
        }

        double get_ingresos(){
            return ingresos;
        }

        void set_nom_emp(string _nom_emp){
            nom_emp = _nom_emp;
        }

        void set_rS(string _rS){
            rS = _rS;
        }

        void set_direccion(string _direccion){
            direccion = _direccion;
        }

        void set_nom_dir(string _nom_dir){
            nom_dir = _nom_dir;
        }

        void set_num_emp(int _num_emp){
            num_emp = _num_emp;
        }

        void set_ingresos(double _ingresos){
            ingresos = _ingresos;
        }

        Pyme() : nom_emp("default"), rS(""), direccion(""), nom_dir(""), num_emp(0), ingresos(0) {} //Constrcutor default
        Pyme(string _nom_emp, string _rS, string _direccion, string _nom_dir, int _num_emp, double _ingresos) : nom_emp(_nom_emp), rS(_rS), direccion(_direccion), nom_dir(_nom_dir), num_emp(_num_emp), ingresos(_ingresos) {}

};

/*

Pyme::Pyme(string _nom_emp, string _rS, string _direccion, string _nom_dir, int _num_emp, double _ingresos){
    nom_emp = _nom_emp;
    rS = _rS;
    direccion = _direccion;
    nom_dir = _nom_dir;
    num_emp = _num_emp;
    ingresos = _ingresos;
}

*/

class Empleado : public Pyme{

    private:
        string nom, puesto;
        string nom_emp_e, rS_e, direccion_e;
        int edad, sueldo;
        Pyme pyme;

    public:
        Empleado(string, string, int, int, Pyme);

        string get_nom(){
            return nom;
        }

        string get_puesto(){
            return puesto;
        }

        int get_edad(){
            return edad;
        }

        int get_sueldo(){
            return sueldo;
        }

        string get_nom_emp_e(){
            return pyme.get_nom_emp();
        }

        string get_direccion_e(){
            return pyme.get_direccion();
        }

        string get_rS_e(){
            return pyme.get_rS();
        }

        void set_nom(string _nom){
            nom = _nom;
        }

        void set_puesto(string _puesto){
            puesto = _puesto;
        }

        void set_edad(int _edad){
            edad = _edad;
        }

        void set_sueldo(int _sueldo){
            sueldo = _sueldo;
        }

        Empleado() : nom(""), puesto(""), edad(0), sueldo(0), Pyme() {}


};

Empleado::Empleado(string _nom, string _puesto, int _edad, int _sueldo, Pyme _pyme){
    nom = _nom;
    puesto = _puesto;
    edad = _edad;
    sueldo = _sueldo;
    pyme = _pyme;
}

int main(){

    /*

    Pyme pyme1("Lalo Taqueria", "Moral", "Paseo de las flores", "Lalo", 200, 12000);
    Empleado emp1("Alex", "Mesero", 18, 350, pyme1);

    cout<<"El nombre de la pyme es: "<<pyme1.get_nom_emp()<<endl;
    cout<<"La direccion de la pyme es: "<<pyme1.get_direccion()<<endl;
    cout<<"La razon social de la pyme es: "<<pyme1.get_rS()<<endl;
    cout<<"El dueno de la pyme es: "<<pyme1.get_nom_dir()<<endl;
    cout<<"La pyme tiene "<<pyme1.get_num_emp()<<" empleados"<<endl;
    cout<<"La pyme genera $"<<pyme1.get_ingresos()<<endl;

    cout<<"------------------------------------------------------------"<<endl;

    cout<<"El nombre del empleado es: "<<emp1.get_nom()<<endl;
    cout<<"El empleado trabaja en: "<<emp1.get_nom_emp_e()<<endl;
    cout<<"El empleado tiene el puesto de: "<<emp1.get_puesto()<<endl;
    cout<<"El empleado tiene "<<emp1.get_edad()<<" anos"<<endl;
    cout<<"El empleado gana $"<<emp1.get_sueldo()<<endl;
    cout<<"La razon social de la empresa donde trabaja es: "<<emp1.get_rS_e()<<endl;
    cout<<"La direccion de la pyme donde trabaja el empleado es: "<<emp1.get_direccion_e()<<endl;

    */

    char op;
    int n = 0;
    int z = 0;

    bool hay_pymes = false;
    bool existe_pyme = false;
    bool existe_empleado = false;

    string nom_pyme, direccion, rS, nom_dir, nom_emp, puesto, desechable;
    int num_trab, edad, sueldo;
    double ingresos;

    int tamano_lista = 30;

    Pyme lista_pymes[tamano_lista];
    Empleado lista_empleados[tamano_lista];


    while (true){

        cout<<"---------------------------------------------------"<<endl;
        cout<<"A - Agregar Pyme"<<endl;
        cout<<"B - Agregar empleado"<<endl;
        cout<<"C - Consultar Pyme"<<endl;
        cout<<"D - Consultar empleado"<<endl;
        cout<<"E - Salir"<<endl;

        cout<<"Introduce la opcion deseada: ";
        cin>>op;

        switch (op)
        {
        case 'A':
            
            cout<<"---------------------------------------------------"<<endl;
            cout<<"Registra los datos que se te piden"<<endl;
            getline(cin, desechable);
            cout<<"Introduce el nombre de la Pyme: ";
            getline(cin, nom_pyme);
            cout<<"Introduce la direccion de la Pyme: ";
            getline(cin, direccion);
            cout<<"Introduce la razon social de la Pyme: ";
            getline(cin, rS);
            cout<<"Introduce el nombre del director de la Pyme: ";
            getline(cin, nom_dir);
            cout<<"Introduce el numero de empleados de la Pyme: ";
            cin>>num_trab;
            cout<<"Introduce los ingresos anuales de la Pyme: $";
            cin>>ingresos;

            

            lista_pymes[n] = Pyme(nom_pyme, rS, direccion, nom_dir, num_trab, ingresos);      

            n++;

            break;

        case 'B':
            cout<<"---------------------------------------------------"<<endl;
            for (int i = 0; i < tamano_lista; i++)
            {
                if(lista_pymes[i].get_nom_emp() != "default"){
                    cout<<i+1<<" - "<<lista_pymes[i].get_nom_emp()<<endl;
                    hay_pymes = true;
                }
                
            }

            if (hay_pymes){

                cout<<"69 - Salir al menu principal"<<endl;
                cout<<"Introduce el numero de la Pyme a la que quieres agregar al empleado: ";
                cin>>op;

                if (op == 69){
                    break;
                }

                cout<<"---------------------------------------------------"<<endl;

                cout<<"Introduce los datos que se te piden"<<endl;
                getline(cin, desechable);
                cout<<"Nombre del empleado: ";
                getline(cin, nom_emp);
                cout<<"Puesto del empleado: ";
                getline(cin, puesto);
                cout<<"Edad del empleado: ";
                cin>>edad;
                cout<<"Sueldo del empleado: $";
                cin>>sueldo;

                lista_empleados[z] = Empleado(nom_emp, puesto, edad, sueldo, lista_pymes[op-1]);
                z++;

                break;

            }else{
                cout<<"No hay ninguna Pyme registrada. Primero anade algunas."<<endl;
                break;
            }

        case 'C':
            cout<<"---------------------------------------------------"<<endl;
            getline(cin, desechable);
            cout<<"Introduce el nombre de la Pyme que quieras buscar: ";
            getline(cin, nom_pyme);

            for (int i = 0; i < tamano_lista; i++)
            {
                if(lista_pymes[i].get_nom_emp() == nom_pyme){
                    cout<<"Nombre Pyme: "<<lista_pymes[i].get_nom_emp()<<endl;
                    cout<<"Direccion: "<<lista_pymes[i].get_direccion()<<endl;
                    cout<<"Razon Social: "<<lista_pymes[i].get_rS()<<endl;
                    cout<<"Dueno: "<<lista_pymes[i].get_nom_dir()<<endl;
                    cout<<"Cantidad de empleados: "<<lista_pymes[i].get_num_emp()<<endl;
                    cout<<"Ingresos anuales: $"<<lista_pymes[i].get_ingresos()<<endl; 

                    existe_pyme = true;
                }
            }

            if(!existe_pyme){
                cout<<"Al parecer esa Pyme no esta registrada. Escribiste bien el nombre?"<<endl;
            }

            existe_pyme = false;



            break;

        
        case 'D':
            cout<<"---------------------------------------------------"<<endl;
            getline(cin, desechable);
            cout<<"Introduce el nombre del empleado que quieras buscar: ";
            getline(cin, nom_emp);

            for (int i = 0; i < tamano_lista; i++)
            {
                if(lista_empleados[i].get_nom() == nom_emp){
                    cout<<"Nombre: "<<lista_empleados[i].get_nom()<<endl;
                    cout<<"Pyme en que trabaja: "<<lista_empleados[i].get_nom_emp_e()<<endl;
                    cout<<"Puesto: "<<lista_empleados[i].get_puesto()<<endl;
                    cout<<"Edad: "<<lista_empleados[i].get_edad()<<endl;
                    cout<<"Sueldo: $"<<lista_empleados[i].get_sueldo()<<endl;
                    cout<<"Razon Social de Pyme en que trabaja: "<<lista_empleados[i].get_rS_e()<<endl;
                    cout<<"Direccion de Pyme en que trabaja: "<<lista_empleados[i].get_direccion_e()<<endl;

                    existe_empleado = true;
                }
            }

            if(!existe_empleado){
                cout<<"Al parecer este empleado no esta registrado. Escribiste bien el nombre?"<<endl;
            }

            existe_empleado = false;



            break;
        
        case 'E':
            exit(1);
        
        default:
            cout<<"Has introducido una opcion no valida"<<endl;
            break;
        }

    }


    return 0;
}