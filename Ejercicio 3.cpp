#include <iostream>
using namespace std;
float porcentaje,fm;
int edad, genero, i,f,m, opcion, infraccion,edadmayor;
string nombre, nombremayoredad, grua;
void edadesgrua (){
	do{
	
cout<<"¿Utilizo Grua?/s/n"<<endl;
		cin>>grua;
			if (grua!="s" && grua!="S" && grua!="n" && grua!="N") {
			cout<<"Respuesta invalida";
		}
			} while( grua!="s" && grua!="S" && grua!="n" && grua!="N");
		if(grua=="s" || grua=="S" ){
		if(edad>edadmayor){
			edadmayor=edad;
			nombremayoredad=nombre;
		}
		}
}
int main(int argc, char** argv) {
	cout<<"Vamos a continuacion mostrar las infracciones del dia sabado"<<endl;
	cout<<"Para terminar el programa simplemente digite el numero 0 "<<endl;
	opcion=1;
	i=0;
	f=0;
	m=0;
	fm=0;
	edadmayor=0;
	while (opcion!=0){
		
			cout<<"tipo de infraccion"<<endl;
		cout<<"1.Exceso de velocidad, 2.otros"<<endl;
		cin>>infraccion;
		cout<<"Nombre del infractor"<<endl;
		cin>>nombre;
		cout<<"Edad del infractor"<<endl;
		cin>>edad;
		cout<<"Genero del infractor"<<endl;
		cout<<"1.femenino y 2.masculino"<<endl;
		cin>>genero;
		if (genero==1){
		cout<<"Infractor femenino"<<endl;
		f=f+1;
		} 
		else if (genero==2) {
		cout<<"Infractor Maculino"<<endl;
		m=m+1;	
		}
		edadesgrua();
	if (infraccion==1 && genero==1){
		fm=fm+1;
	}

	i++;
	cout<<"Desea terminar el programa, pulse 0 para terminar"<<endl;
	cin>>opcion;
     }
	 porcentaje=(fm/i)*100;
	cout<<"El total de infractores fue"<<i<<endl;
	cout<<"De los cuales "<<f<<"fueron mujeres, y"<<m<<"fueron hombres"<<endl;
	cout<<"Con un porcentaje de"<<porcentaje<<"%"<<"De infractores femeninos por exceso de velocidad"<<endl;
	cout<<"El infractor con mayor edad que utilizo la grua fue"<<nombremayoredad<<"con una edad de"<<edadmayor<<"años";
	
		return 0;

}

