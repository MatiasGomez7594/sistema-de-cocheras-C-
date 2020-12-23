#include <iostream>
#define CAPACIDAD 10
using namespace std;

struct Ingreso{
	int opcion;
	string numPatente;
	int numCochera;
	string horaEntrada;
};

struct Cochera{
	int iCochera;
	string espacio;
	string horaIngreso;
};

int AsignarCochera(Cochera miCochera[],int numCochera,int tope,string patente,string hora){
	int verificacion=0;
	int i=0;
	if(numCochera <1 || numCochera > 10 ){
		verificacion = -1;
		cout<<"Error! El numero de cochera no existe"<<endl;
	}else{
		while(i<tope and verificacion==0){
			if(miCochera[i].iCochera == numCochera and miCochera[i].espacio == "libre"){
				miCochera[i].espacio = patente;
				miCochera[i].horaIngreso = hora;
				verificacion=1;
				cout<<"El auto se guardo correctamente"<<endl;
				
			}
	    	i++;	
		}
		
	}
	if(i==tope){
		cout<<"Todas las cocheras se encuentran ocupadas"<<endl;
		verificacion = 1;
	}

	return verificacion;
}
void SalidaVehiculo(Ingreso &miIngreso, Cochera miCochera[],int tope){
	cout<<"Ingrese el numero de patente del vehiculo que quiere retirar: ";
	cin>>miIngreso.numPatente;
	int i=0;
	bool verificacion=false;
	while(i<tope and verificacion ==false){
		if(miCochera[i].espacio==miIngreso.numPatente){
			cout<<"*El vehiculo ingreso a las "<<miCochera[i].horaIngreso<<" hs";
			miCochera[i].espacio="libre";
			verificacion=true;
			cout<<" y fue retirado correctamente "<<endl;
			cout<<endl;
		}
		i++;
	}
	if(verificacion==false){
		cout<<"*No se encontro el vehiculo "<<endl;
		cout<<endl;
	}
}
void VerListaVehiculos(Ingreso &miIngreso,Cochera miCochera[],int tope){
	int i;
	bool verificacion=false;
		cout<<"Listado de coches que se encuentran en la cochera"<<endl;
		for(i=0;i<tope;i++){
			if(miCochera[i].espacio != "libre"){
				verificacion=true;
				cout<<"*En la cochera Nro."<<miCochera[i].iCochera<<" se encuentra el vehiculo cuya patente es "
			    <<miCochera[i].espacio<<" que ingreso a las "<<miCochera[i].horaIngreso<<" hs"<<endl;
		    }
	    }
	    if(verificacion == false){
			cout<<"*No hay ningun vehiculo en la cochera";
			cout<<endl;
	    }
}
bool VerificarCocheraVacia(Ingreso &miIngreso,Cochera miCochera[],int tope){
	int i;
	bool verificacion=true;
	for(i=0;i<tope;i++){
		if(miCochera[i].espacio != "libre"){
			cout<<"Atencion! Aun no salio el vehiculo cuyo Nro. de patente es "
			<<miCochera[i].espacio<<endl;
			verificacion =false;
		}
	}
	return verificacion;
}
void IngresoVehiculo(Ingreso &miIngreso,Cochera miCochera[],int tope){
	cout<<"Ingrese el numero de patente del vehiculo: ";
	cin>>miIngreso.numPatente;
	cout<<"Introduzca la hora (por ejemplo 1:30 o 11): ";
	cin>>miIngreso.horaEntrada;	
	cout<<"Ingrese el numero de cochera (1/10) donde quiere estacionar: ";
	cin>>miIngreso.numCochera;
	while(AsignarCochera(miCochera,miIngreso.numCochera,tope,miIngreso.numPatente,miIngreso.horaEntrada)!=1){
		cout<<"Reingrese el numero de cochera (1/10) donde quiere estacionar: ";
	    cin>>miIngreso.numCochera;
	    cout<<endl;
	}
}

void OpcionMenu(Ingreso &miIngreso,Cochera miCochera[],int tope){
	cout<<"------Bienvenido------"<<endl;
	cout<<"Las opciones del menu son: "<<endl;
	cout<<"1-Entrada de vehiculo"<<endl;
	cout<<"2-Salida de vehiculo"<<endl;
	cout<<"3-Listado de vehiculos"<<endl;
	cout<<"4-Fin"<<endl;
	cout<<endl;
	cout<<"Ingrese el numero de opcion: ";
	cin>>miIngreso.opcion;
	while(miIngreso.opcion != 4){
	    if(miIngreso.opcion==1)IngresoVehiculo(miIngreso,miCochera,tope);
		else if(miIngreso.opcion==2)SalidaVehiculo(miIngreso,miCochera,tope);
		else if(miIngreso.opcion==3)VerListaVehiculos(miIngreso,miCochera,tope);
		else{
			cout<<"Opcion incorrecta! "<<endl;
	    }
	    cout<<endl;
	    cout<<"Elija su opcion: "<<endl;
	    cout<<"1-Entrada de vehiculo"<<endl;
	    cout<<"2-Salida de vehiculo"<<endl;
	    cout<<"3-Listado de vehiculos"<<endl;
	    cout<<"4-Fin"<<endl;
	    cout<<endl;
	    cout<<"Ingrese el numero de opcion: ";
	    cin>>miIngreso.opcion;

	}
	if(miIngreso.opcion==4){
		while(VerificarCocheraVacia(miIngreso,miCochera,tope)==0){
		cout<<"Retire todos los vehiculos para poder finalizar "<<endl;
		SalidaVehiculo(miIngreso,miCochera,tope);
	   }	
	}
}
int main(){
	Ingreso miIngreso;
	Cochera miCochera[CAPACIDAD]={1,"libre","hora",2,"libre","hora",3,"libre",
	"hora",4,"libre","hora",5,"libre","hora",
	6,"libre","hora",7,"libre","hora",8,"libre","hora",9,"libre","hora",10,"libre","hora"};
	OpcionMenu(miIngreso,miCochera,CAPACIDAD);
	return 0;
}
