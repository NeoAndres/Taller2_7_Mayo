#include <iostream>
#include <string> 
using namespace std;
const int anio_actual = 2025;
const int mes_actual = 5;
int calcularedad( int anio, int mesnacimiento) {
    int edad_en_meses = (anio_actual - anio) * 12 + (mes_actual - mesnacimiento);
    return edad_en_meses;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int identificacion, identificacionmayor, anio, mesnacimiento, meses, opcion, raza,cantBeagle = 0, cantBoxer = 0, cantLabrador = 0, cantBulldog = 0,cantidadMayorVenta,edadmayor;
float valorventa,totalventa,totalBeagle = 0, totalBoxer = 0, totalLabrador = 0, totalBulldog = 0,mayorVenta;
string nombreraza, razaMayorVenta,nombrerazamayor;


int main(int argc, char** argv) {
	totalventa=0;
	mayorVenta = totalBeagle;
razaMayorVenta = "Beagle";
cantidadMayorVenta = cantBeagle;
edadmayor=0;
identificacion=1;
do{

	do{  cout << "De que de raza es el perro (1=Beagle, 2=Boxer, 3=Labrador, 4=Bulldog): "<<endl;
			cin>> raza;
           if (raza < 1 || raza > 4) {
                cout << "Raza no valida. Intenta de nuevo." << endl;
            }

    }  while (raza < 1 || raza > 4);
			cout<<"Identificacion del canino es:"<<endl<<identificacion<<endl;
	switch (raza){
		
		case 1:
		valorventa = 600;
		nombreraza= "Beagle";
		totalBeagle= totalBeagle+valorventa;
		 cantBeagle++;
		break;
		case 2:
		valorventa= 1300;
		nombreraza= "Boxer";
				totalBoxer= totalBoxer+valorventa;
            cantBoxer++;
		break;
		case 3:
			valorventa= 1000;
		nombreraza= "Labrador";
				totalLabrador= totalLabrador+valorventa;
				cantLabrador++;
		break;
		case 4:
			valorventa= 1750;
		nombreraza= "Bulldog";
				totalBulldog= totalBulldog+valorventa;
            cantBulldog++;
		break;
	
	}  do{
		cout<<"Anio de nacimiento";
		cin>>anio;
	    cout<<"mes de nacimiento";
		cin>>mesnacimiento;		  
		if (anio>anio_actual || mesnacimiento>12 || mesnacimiento<1) {
                cout << "Fecha no valida. Intenta de nuevo." << endl;
            }
	} while (anio>anio_actual || mesnacimiento>12 || mesnacimiento<1);
			  meses = calcularedad(  anio, mesnacimiento);

        cout << "Edad del canino: " << meses << " meses." << endl;
        if(edadmayor<meses){
        	edadmayor=meses;
        	nombrerazamayor=nombreraza;
        	identificacionmayor=identificacion;
		}
		cout<<"Quieres salir del programa 1.si, 2.seguir";
		cin>>opcion;
	totalventa=totalventa+valorventa;
	identificacion++;
	 	 }while (opcion==2);
	 	 if (totalBeagle > mayorVenta) {
    mayorVenta = totalBeagle;
    razaMayorVenta = "Beagle";
    cantidadMayorVenta = cantBeagle;
}
	if (totalBoxer > mayorVenta) {
    mayorVenta = totalBoxer;
    razaMayorVenta = "Boxer";
    cantidadMayorVenta = cantBoxer;
}
if (totalLabrador > mayorVenta) {
    mayorVenta = totalLabrador;
    razaMayorVenta = "Labrador";
    cantidadMayorVenta = cantLabrador;
}
if (totalBulldog > mayorVenta) {
    mayorVenta = totalBulldog;
    razaMayorVenta = "Bulldog";
    cantidadMayorVenta = cantBulldog;
}
cout<<"El valor total de la venta es $"<<totalventa<<endl;
cout << "La raza con mayor valor en ventas es: " << razaMayorVenta<<endl;
cout << "La cantidad de caninos vendidos de esa raza es: " << cantidadMayorVenta<<endl;
cout << "Valor total de ventas de esa raza: $" << mayorVenta<<endl;
cout<< "El canino con mayor edad tiene como identificacion"<<identificacionmayor<<endl<<"Es de la raza"<<nombrerazamayor<<endl<<"y su edad en meses es"<<edadmayor;
	return 0;

}
