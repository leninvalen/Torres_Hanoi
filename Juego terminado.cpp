#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<math.h>
#include <locale.h>
using namespace std;
int opcion;
string continuar;
string opcion_comp="si";
void menu();
void insertar_pila();
int num_discos;
int contador=0;
//PARA SACAR LA FORMULA DE LOS MOVIMIE�9yiNTOS
int num_movimientos=0;
int movimientos_pred;
//SI ES PAR VA A LA SEGUNDA SI ES IMPAR A LA TERCERA

//METODOS PARA RECUPERAR
void recuperar(int);
void recuperar2(int);
void recuperar3(int);
int torre_env;


struct nodo 
{
    int info;
    struct nodo *sig;
};

//variable global que apunta al primer nodo de la lista
struct nodo *pila_a=NULL;
struct nodo *contenedor=NULL;
struct nodo *pila_b=NULL;
struct nodo *pila_c=NULL;
 //VARIABLES PARA LA CONDICI�N
 struct nodo *primera_dir=NULL;
 struct nodo *primera_dir2=NULL;
 struct nodo *primera_dir3=NULL;
 

void insertar(int x)
{
	
    struct nodo *nuevo;
    
    nuevo=(struct nodo*)malloc(sizeof(struct nodo)); //reservar la memoria dinamica
    nuevo->info = x;
    
    if (pila_a == NULL)
    {
        pila_a = nuevo;
        nuevo->sig = NULL;
        
    }
    
    else
    {
		nuevo->sig = pila_a;
        	//AQU� EST� LA CONDICI�N DEL N�MERO COLOCADO ES MAYOR NO SE PUEDE
    	if(nuevo->sig->info<x)
    	{
    		
    		fflush(stdin);
    		cout<<"El numero introducido es mayor"<<endl;
    		system("color c");
    		cout<<"Por favor ingresa desde que torre enviaste (2 o 3) ";
    		cin>>torre_env;
    		if(torre_env==2)
    		{
    			recuperar2(x);  		
			}
			if(torre_env==3)
			{
				recuperar3(x);
			}
    		system("pause");
    		
		}
		else
		{
			pila_a = nuevo;
        
		}	
	}
}

void imprimir()
{
	if(pila_a==NULL)
	{
		cout<<"Est� vac�a"<<endl;
		system("pause");
		return menu();
	}
    struct nodo *reco=pila_a;
    if(reco==NULL)
    printf("\n No has ingresado discos mijin \n");
        
	while (reco!=NULL)
    {
       cout<<"\t---"<<reco->info<<"---"<<endl;
        reco=reco->sig;
    }
    
}

int cantidad()
{
    struct nodo *reco = pila_a;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

void insertar_pila2(int num2)
{
struct nodo *nuevo2;
    
    nuevo2=(struct nodo*)malloc(sizeof(struct nodo)); //reservar la memoria dinamica
    nuevo2->info = num2;
    if (pila_b == NULL)
    {
        pila_b = nuevo2;
        nuevo2->sig = NULL;
        
    }
    else
    {
    	
    	nuevo2->sig = pila_b;
        	//AQU� EST� LA CONDICI�N DEL N�MERO COLOCADO ES MAYOR NO SE PUEDE
    	if(nuevo2->sig->info<num2)
    	{
    		
    		fflush(stdin);
    		cout<<"El numero introducido es mayor"<<endl;
    		system("color c");
    		cout<<"Por favor ingresa desde que torre enviaste (1 o 3) ";
    		cin>>torre_env;
    		if(torre_env==1)
    		{
    			recuperar(num2);  		
			}
			if(torre_env==3)
			{
				recuperar3(num2);
			}
    		system("pause");
    		
		}
		else
		{
			pila_b = nuevo2;
        
		}
    }
}
void imprimir2()
{
	if(pila_b==NULL)
	{
		cout<<"b";
		system("pause");
		return menu();
	}
    struct nodo *reco2=pila_b;
    if(reco2==NULL)
    printf("\n No has ingresado discos mijin \n");
    
	while (reco2!=NULL)
    {
        cout<<"\t---"<<reco2->info<<"---"<<endl;
        reco2=reco2->sig;
    }
    
}

int cantidad2()

{
    struct nodo *reco2 = pila_b;
    int cant2 = 0;
    while (reco2 != NULL)
    {
        cant2++;
        reco2 = reco2->sig;
    }
    return cant2;
}

void insertar_pila3(int num3)
{
	struct nodo *nuevo3;
    //RECUPERAR VACIO	
	//NORMAL
    nuevo3=(struct nodo*)malloc(sizeof(struct nodo)); //reservar la memoria dinamica
    nuevo3->info = num3;
    
    if (pila_c == NULL)
    {
        pila_c = nuevo3;
        nuevo3->sig = NULL;
        contador++;
    }
    else
    {
    	//AQU� EST� LA CONDICI�N DEL N�MERO COLOCADO ES MAYOR NO SE PUEDE
    	nuevo3->sig = pila_c;
        	//AQU� EST� LA CONDICI�N DEL N�MERO COLOCADO ES MAYOR NO SE PUEDE
    	if(nuevo3->sig->info<num3)
    	{
    		
    		fflush(stdin);
    		cout<<"El numero introducido es mayor"<<endl;
    		system("color c");
    		cout<<"Por favor ingresa desde que torre enviaste (1 o 2) ";
    		cin>>torre_env;
    		if(torre_env==1)
    		{
    			recuperar(num3);  		
			}
			if(torre_env==2)
			{
				recuperar2(num3);
			}
    		system("pause");
    		
		}
		else
		{
			pila_c = nuevo3;
			contador++;
        
		}
	}
}
void imprimir3()
{
	if(pila_c==NULL)
	{
		cout<<"c";
		system("pause");
		return menu();
	}
    struct nodo *reco3=pila_c;
    if(reco3==NULL)
    {
    	cout<<"No has ingresado discos mijin "<<endl;
	}
    
	while (reco3!=NULL)
    {
        cout<<"\t---"<<reco3->info<<"---"<<endl;
        reco3=reco3->sig;
        
    }
    
}
//METODOS RECUPERAR
void recuperar(int num_rec)
{
		insertar(num_rec);
}
void recuperar2(int num_rec)
{
		insertar_pila2(num_rec);
}
void recuperar3(int num_rec)
{
		insertar_pila3(num_rec);
}


int cantidad3(){
    struct nodo *reco3 = pila_c;
    int cant3 = 0;
    while (reco3 != NULL)
    {
        cant3++;
        reco3 = reco3->sig;
    }
    return cant3;
}
int vacia()
{
    if (pila_a == NULL)
        return 1;
    else
        return 0;
}

int extraer()
{
	
    if (pila_a != NULL)
    {
    	int elec_torre;
        int informacion = pila_a->info;
        
        struct nodo *bor = pila_a;
        
		pila_a = pila_a->sig;
        
		free(bor);//a asignaci�n y liberaci�n din�mica de memoria 
		
		cout<<"Lista de torres"<<endl;
		cout<<"1. Primera torre"<<endl;
		cout<<"2. Segunda torre"<<endl;
		cout<<"3. Tercera torre"<<endl;
        
        cout<<"En que torre desea colocarla? ";
        cin>>elec_torre;
        if(elec_torre==1)
        {
        	insertar(informacion);
        	imprimir();
		}
		if(elec_torre==2)
		{
			insertar_pila2(informacion);
			imprimir2();
		}
		if(elec_torre==3)
		{
			insertar_pila3(informacion);
			imprimir3();
		}
		return informacion;
        
    }
    
	else
    {
        return -1;
    }
}

int extraer2()
{
	
    if (pila_b != NULL)
    {
    	int elec_torre;
        int informacion = pila_b->info;
        
        struct nodo *bor2 = pila_b;
        
		pila_b = pila_b->sig;
        contenedor=pila_b;
		free(bor2);
		
		cout<<"Lista de torres"<<endl;
		cout<<"1. Primera torre"<<endl;
		cout<<"2. Segunda torre"<<endl;
		cout<<"3. Tercera torre"<<endl;
        
        cout<<"En que torre desea colocarla? ";
        cin>>elec_torre;
        if(elec_torre==1)
        {
        	insertar(informacion);
        	imprimir();
		}
		if(elec_torre==2)
		{
			insertar_pila2(informacion);
			imprimir2();
		}
		if(elec_torre==3)
		{
			insertar_pila3(informacion);
			imprimir3();
		}
		return informacion;
        
    }
    
	else
    {
        return -1;
    }
}
int extraer3()
{
	
    if (pila_c != NULL)
    {
    	int elec_torre;
        int informacion = pila_c->info;
        
        struct nodo *bor3 = pila_c;
        
		pila_c = pila_c->sig;
        contenedor=pila_c;
		free(bor3);
		
		cout<<"Lista de torres"<<endl;
		cout<<"1. Primera torre"<<endl;
		cout<<"2. Segunda torre"<<endl;
		cout<<"3. Tercera torre"<<endl;
        
        cout<<"En que torre desea colocarla? ";
        cin>>elec_torre;
        if(elec_torre==1)
        {
        	insertar(informacion);
        	imprimir();
		}
		if(elec_torre==2)
		{
			insertar_pila2(informacion);
			imprimir2();
		}
		if(elec_torre==3)
		{
			insertar_pila3(informacion);
			imprimir3();
		}
		return informacion;
        
    }
    
	else
    {
        return -1;
    }
}

void menu()
{
	
	system("cls");
	system("color 7");
	if(movimientos_pred!=0)
	{
		cout<<"Movimientos que se deben realizar = "<<movimientos_pred<<endl;
		if(num_movimientos==movimientos_pred)
		{
			cout<<"Este es tu l�mite de movimientos"<<endl;
			if(cantidad3()==num_discos)
			{
				system("color 9c");
				cout<<"Ganaste mijin felicitaciones"<<endl;
				imprimir3();
				
			}
			
			cout<<"�Desea continuar jugando?(Escriba si o no) ";
			cin>>continuar;
			if(continuar==opcion_comp)
			{
				movimientos_pred=0;
				num_movimientos=0;
				while(pila_a!=NULL)
				{
					struct nodo *continua = pila_a;
        			pila_a = pila_a->sig;
        			free(continua);
					
				}
				
				while(pila_c!=NULL)
				{
					struct nodo *continua2 = pila_c;
        			pila_c = pila_c->sig;
        			free(continua2);
					
				}
				while(pila_b!=NULL)
				{
					struct nodo *continua3 = pila_b;
        			pila_b = pila_b->sig;
        			free(continua3);
					
				}
				return menu();
			}
			exit (1);
		}
	}
					
	cout<<"N�mero de movimientos = "<<num_movimientos<<endl;
	if (pila_a!=NULL)
	{
		cout<<"Estado de la torre 1 = "<<cantidad()<<" discos(s)"<<endl;
	    imprimir();
		cout<<"------------------------"<<endl;
	}
	if(pila_b!=NULL)
	{
		cout<<"Estado de la torre 2 = "<<cantidad2()<<"  disco(s)"<<endl;
	   imprimir2();
		cout<<"------------------------"<<endl;	
	}
	if(pila_c!=NULL)
	{

		cout<<"Estado de la torre 3 = "<<cantidad3()<<"  disco(s)"<<endl;
		imprimir3();
		cout<<"--------------------------"<<endl;	
	}
	
	//PAR O IMPAR 
	if(num_discos!=0)
	{
				if(num_discos%2==0)//par
			{
				cout<<"Esta torre es par"<<endl;
				cout<<"Pista: El primer disco ir� a la segunda torre"<<endl;
			}
			//IMPAR
			if(num_discos%2!=0)
			{
				cout<<"Esta torre es impar"<<endl;
				cout<<"Pista: El primer disco ir� a la tercera torre"<<endl;
			}
	}
	
	
	int torres;
	cout<<"--------------------------------------"<<endl;
	cout<<"Men�"<<endl;
	cout<<"1.Selecci�n de los discos para jugar"<<endl;
    cout<<"2.Mostrar torre "<<endl;
    cout<<"3.Mover torre "<<endl;
    cout<<"4.Salir del juego"<<endl;
    cin>>torres;
    switch(torres)
    {
    	case 1:
    		{
    			
    			cout<<"Escribe el n�mero de discos con los que desea jugar: ";
    			cin>>num_discos;
    					//C�DIGO QUE INDICA EL N�MERO DE MOVIMIENTOS A REALIZAR
    					
    					movimientos_pred=(pow(2,num_discos)-1);
    					
    			
				
    			for(int i=num_discos;i>0;i--)
    			{
    				insertar(i);
				}
				system("pause");
				return menu();
			}
			break;
				
				case 2:
					{
						int op_torre;
						cout<<"�Qu� torre desea mostrar? (1,2,3)";
						cin>>op_torre;
						if(op_torre==1)
						{
							imprimir();
							num_movimientos++;
							system("pause");
							return menu();
						}
							if(op_torre==2)
							{
								imprimir2();
								num_movimientos++;
								system("pause");
								return menu();
							}
								
								if(op_torre==3)
								{
									imprimir3();
									num_movimientos++;
									system("pause");
									return menu();
								}
					}
					break;
					case 3:
						{
							cout<<"TORRES PARA MOVER"<<endl;
							cout<<"1. Torre 1"<<endl;
							cout<<"2. Torre 2"<<endl;
							cout<<"3. Torre 3"<<endl;
							cout<<"Elija de que torre desea mover"<<endl;
							cin>>opcion;
							if(opcion==1)
							{
								num_movimientos++;
								int obtener;
								obtener=extraer();
								if(obtener==-1)
								{
								cout<<"No hay ning�n disco aqu� pues mijin ;v"<<endl;
								system("pause");
								return menu();
								
								}
								
								system("pause");
								return menu();
							}
							
							if(opcion==2)
							{
								num_movimientos++;
								int obtener;
								obtener=extraer2();
								if(obtener==-1)
								{
								cout<<"No hay ning�n disco aqu� pues mijin ;v"<<endl;
								system("pause");
								return menu();
								
								}
								system("pause");
								return menu();
								
							}
							
							if(opcion==3)
							{
								num_movimientos++;
								int obtener;
								obtener=extraer3();
								if(obtener==-1)
								{
								cout<<"No hay ning�n disco aqu� pues mijin ;v"<<endl;
								system("pause");
								return menu();
								
								}
								system("pause");
								return menu();
								
							}
						}
						break;
						
							case 4:
								{
									cout<<"GRACIAS POR JUGAR PANA";
    								exit (1);
								}
								break;
	}
	
}

int main()
{
	
	setlocale(LC_ALL,"spanish");
	menu();
	
    return 0;
}
