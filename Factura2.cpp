# include <iostream>
# include <string>
# include <sstream> //permite construir  cadena de caracteres 
# include <vector> //
# include <cstdlib>// convierte string en double


using namespace std;

string  encabezado(){

 string nombre, ruc, fecha;
 ostringstream  encabezado; // Variable para construir la variable 
 
 //Datos del encabezado
 cout<<"Ingrese nombre: "; getline(cin,nombre);
 cout<<"Ingrese RUC: "; cin>>ruc;
 cout<<"Ingrese Fecha: "; cin>>fecha;
 
 encabezado<<"\n-----------------------------------------"
		   <<"\n                FACTURA                  "
		   <<"\n-----------------------------------------"
		   <<"\nN.- de Factura        001"
		   <<"\nFecha de Emision:" << fecha
		   <<"\n-----------------------------------------"
		   <<"\nDATOS DEL CLIENTE"
		   <<"\n-----------------------------------------"
		   <<"\nNombre: "<< nombre
		   <<"\nRUC: "<< ruc
		   <<"\n-----------------------------------------";
		   
 return encabezado.str();
}

string detalle(){
	
	int cantidad; string detalle; double precio;
	ostringstream cadena;
	
	cout<<"\nIngrese Cantidad: "; cin>>cantidad;
	cout<<"Ingrese detalle: ">cin>>detalle;
	cout<<"Ingrese Precio unitario: ";cin>>precio;
	cadena<<cantidad<<"     "<<detalle<<"  $"<<precio;
	
	return cadena.str();
}

vector<string> detalle_factura(){
	vector<string>detalles;
	bool opcion=1;
	ostringstream  cadena;
	ostringstream  aux;
	aux<<"\nDETALLES DE LA FACTURA       "
	   <<"\n-----------------------------------------";
	detalles.push_back(aux.str());
	int contador=0;
	while(opcion){
		detalles.push_back(detalle());
		cout<<"Desea ingresar otro detalle, presione (1): SI o (0):No? ";cin>>opcion;
		contador++;
	}
	return detalles;
}

int main (){
	string factura=encabezado();
	vector<string> detalles=detalle_factura();
	double subtotal[10];
	double suma;
	int k=0;
	
	cout <<factura<<endl;
	
	//imprimir detalle 
	for(size_t i=0;i<detalles.size();i++){
		cout<<detalles[i]<<endl;
		//leer precio
		size_t pos=detalles[i].find("$");
		string aux=detalles[i].substr(pos+1);
		
		//leer cantidad
		size_t pos1=detalles[i].find(" ");
		string cant=detalles[i].substr(0,pos1);
		
		//cantidad* precio
		subtotal[k]=atof(cant.c_str())*atof(aux.c_str());
		k++;
	}
	for(int z=0; z<10;z++){
		suma+=subtotal[z];
	}
	
	
	cout<<"\n-----------------------------------------"<<endl;
	cout<<"Subtotal:              "<<suma<<endl;
	cout<<"IVA:                   "<<suma*0.15<<endl;
	cout<<"Total a Pagar:         "<<suma*1.15<<endl;
	return 0;
	
}
	 
