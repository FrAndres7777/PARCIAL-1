#include<iostream>
#include <fstream>
using namespace std;

void vaciararreglo(char* list);


void agregarMateriaLista();


void materiastxt(char* arr);


void materiaMayus(char* materia);


bool arrIguales(char* arr1,char*arr2);


int obtenerNumeroDia(char* dia);


void horasValidas(int* a , int* b);


void inicializarLista(char** lista, int tamLista, int tamPalabra);


const int TAM_LISTA = 24;
const int TAM_PALABRA = 25;

bool comprobarPosicion(char** lista, int longitud,int posicion);


bool posicionesValidas(char** lista___,int* horaI,int* HoraF);

void seleccionarHoras(int *horaInicio, int *horaFinal);

void agregarPalabra(char** lista, int longitud , int posicion,int posicionFinal,char* palabra);







//void  ubicarMateriaEnHorario(char** list, char* materia);
void  ubicarMateriaEnHorario(char** listLUN,char** listMAR,char** listMIE,char** listJUE,char** listVIE,char** listSAB,char** listDOM, char* materia,char* dia );


void liberarLista(char** lista, int tamLista);





int main(){
	//DANGER
	char** listaLUN = new char*[TAM_LISTA];
	char** listaMAR = new char*[TAM_LISTA];
	char** listaMIE = new char*[TAM_LISTA];
	char** listaJUE = new char*[TAM_LISTA];
	char** listaVIE = new char*[TAM_LISTA];
	char** listaSAB = new char*[TAM_LISTA];
	char** listaDOM = new char*[TAM_LISTA];
	inicializarLista(listaLUN, TAM_LISTA, TAM_PALABRA);
	inicializarLista(listaMAR, TAM_LISTA, TAM_PALABRA);
    inicializarLista(listaMIE, TAM_LISTA, TAM_PALABRA);
    inicializarLista(listaJUE, TAM_LISTA, TAM_PALABRA);
	inicializarLista(listaVIE, TAM_LISTA, TAM_PALABRA);
	inicializarLista(listaSAB, TAM_LISTA, TAM_PALABRA);
	inicializarLista(listaDOM, TAM_LISTA, TAM_PALABRA);
	///
	
    
	//DANGER
	char matDias[1][3][100];//dias para el ciclo de pedir horario de hora se guardaran los dias
	//PENDIENTE VACIAS A MATDIAS POSIBLE ERROR 
    char name[100];
    int  numeroMaterias;
    cout<<"Ingresa tu nombre: ";
    cin.getline(name,100);
    materiaMayus(name);
    cout<<"Hola ";
    for(int i =0; name[i]!='\0'; i++){
        cout<<name[i];
    }
    vaciararreglo(name);
    for(int i =0; name[i]!='\0'; i++){
        cout<<name[i];
    }
    cout<<"\nIngresa Numero de Materias: ";
    cin>> numeroMaterias;
    char materia[100];
    vaciararreglo(materia);
    char listaMaterias[1][numeroMaterias][100];
    cin.ignore();//Ignorar el salto de linea pendiente despues de la entrada anterior
    for(int i = 0 ; i < numeroMaterias ; i++){
        cout<<"\t\tPor Favor Ingresa Materia "<< ":\t";
        vaciararreglo(listaMaterias[0][i]);
        cin.getline(listaMaterias[0][i],100); // permitir espacios al ingresar la materia
        materiastxt(listaMaterias[0][i]);
    }
    // IMPRIMIR MATERIAS MI PEZ
    cout<<"Se registraron tus Materias:\n";
    for(int iii = 0 ; iii< numeroMaterias;iii++){
    	/////
    	
    	cout<<listaMaterias[0][iii]<<endl;
    	
    	int numDias,opcionMatReg;
		///quite hora inicio y final
		// UN NUMERO PARA SABER PARA QUE DIA ESTA ITERANDO Y SABER A QUE LIST___ LLENAR
		int indicadorDiaList;// PENDIENTYE PUEDE DAR UN ERROR
		//
		cout<<"INGRESA DATOS DE MATERIA DIAS:\n\tMartes-Jueves[1]\n\tMiercoles - Viernes[2]\n\tHorario Diferente [3]\n";
        cin>>opcionMatReg;
        while(opcionMatReg>3 or opcionMatReg < 1){
        	cout<<"Elige opcion Valida ";
        	cin>>opcionMatReg;
        }
        if (opcionMatReg<3){
			numDias=2;
			if(opcionMatReg==1){
				char matDias[1][3][25]= {{"MARTES", "JUEVES", ""}};//dias para el ciclo de pedir horario de hora se guardaran los dias
				for(int i = 0; matDias[0][i][0]!= '\0' ; i++){
        			cout<<endl<<matDias[0][i]<<endl;
        			indicadorDiaList=obtenerNumeroDia(matDias[0][i]);
        			ubicarMateriaEnHorario(listaLUN,listaMAR,listaMIE,listaJUE,listaVIE,listaSAB,listaDOM,listaMaterias[0][iii],matDias[0][i]);
        			
    					}
			}else if(opcionMatReg==2){
					char matDias[1][3][25]= {{"MIERCOLES", "VIERNES", ""}};//dias para el ciclo de pedir horario de hora se guardaran los dias
					for(int i = 0; matDias[0][i][0]!= '\0' ; i++){
        				cout<<endl<<matDias[0][i]<<endl;
        				indicadorDiaList=obtenerNumeroDia(matDias[0][i]);
        				ubicarMateriaEnHorario(listaLUN,listaMAR,listaMIE,listaJUE,listaVIE,listaSAB,listaDOM,listaMaterias[0][iii],matDias[0][i]);
    				}
			}
						
					
		}else{
			cin.ignore();
			cout<<"Ingresa Numero dias: ";
			cin>>numDias;
			cin.ignore();
			char matDias[1][3][100]={{"", "", ""}};;
			for(int i = 0; i < numDias ;i++){
				cout<<"\nIngresa Dias ";
				cin.getline(matDias[0][i],25);
				materiaMayus(matDias[0][i]);
				obtenerNumeroDia(matDias[0][i]);
				
				}
			for(int i = 0; matDias[0][i][0]!= '\0' ; i++){
       			cout<<endl<<matDias[0][i]<<endl;
       			indicadorDiaList=obtenerNumeroDia(matDias[0][i]);
       			ubicarMateriaEnHorario(listaLUN,listaMAR,listaMIE,listaJUE,listaVIE,listaSAB,listaDOM,listaMaterias[0][iii],matDias[0][i]);
       			
    			}
			}
		
        //FUNCIONA.ubicarMateriaEnHorario(listaLUN,listaMaterias[0][i]) ; 
        /////
        
        //ubicarMateriaEnHorario(listaLUN,listaMAR,listaMIE,listaJUE,listaVIE,listaSAB,listaDOM,listaMaterias[0][i],matDias);
        
        
    
	}
	//PRUEBA DE IMPRESION
	 cout << endl << "Lista de palabras:" << endl;
    for (int i = 0; i < TAM_LISTA; i++) {
        cout << "Posición " << i << ": ";
        if (listaLUN[i][0] == '\0') {
            cout << "(vacío)";
        } else {
            cout << listaLUN[i];
        }
        cout << endl;
    }
	
	
	
	
    ///LIBERAR MEMORIA DANGER
	liberarLista(listaLUN, TAM_LISTA);
    liberarLista(listaMAR, TAM_LISTA);
    liberarLista(listaMIE, TAM_LISTA);
    liberarLista(listaJUE, TAM_LISTA);
    liberarLista(listaVIE, TAM_LISTA);
    liberarLista(listaSAB, TAM_LISTA);
    liberarLista(listaDOM, TAM_LISTA);
    ///LIBERAR MEMORIA DANGER
    
    return 0;
}




void vaciararreglo(char* list){
	for(int i = 0; i <20;i++){
		list[i]='\0';
	}return;
}

//llega una materia y la pongo el lista de materias

void agregarMateriaLista(char* materia, char* materLista){
	for(int i =0 ; materia[i]!='\0'; i++){
		materLista[i]=materia[i];
	}return;
}


//Funcion comprovar si una materia es lista de materias
void materiastxt(char* list) {
    char arr[100];
    int i = 0;
    bool materiaEsta= false;
    // Abrir el archivo
    ifstream file("Materias.txt");
	
    
    while (file.is_open() and materiaEsta==false) {
        // Leer línea por línea
        while (!file.eof()) {
            // Leer la línea
            char line[100];
            vaciararreglo(arr);
            file.getline(line, 100);
            
            // Recorrer la línea hasta la coma
            for (int j = 0; line[j] != ',' && line[j] != '\0'; j++) {
                arr[i++] = line[j];
            }
            // Agregar un carácter nulo al final del arreglo
            arr[i] = '\0';
            
            // Imprimir el arreglo resultante
            materiaEsta=arrIguales(list,arr);
            int numDias;
            int horaInicio;
            int horaFinal;
            int opcionMatReg;
            //MATERIAS
            //MATERIAS
            // Crear la lista de palabras vacía
    		
            
            
            ///
            if(materiaEsta==true){
            	file.close();
            	return;
			}
            
            // Reiniciar el contador
            i = 0;
        }
        
        // Cerrar el archivo
        if(materiaEsta==false){
        	cout<<"\t\t\tIngresa Materia Valida:";
        	cin.getline(list,100);
        	file.seekg(0);
        	
		}else{
			file.close();
			return;
		}
        
    }
}

void materiaMayus(char* materia){
	for(int i = 0; materia[i] != '\0'; i++){
		if(materia[i]>96  and materia[i] <123){
			materia[i]=materia[i]-32;
		}
	}return;
}

//Funcion Si Arrreglos SON Iguales

bool arrIguales(char* arr1,char*arr2) {
    int len1 =0;
    int len2 =0;
    bool equal = true;
    for(int i = 0;arr1[i] != '\0';i++){
    	len1++;
	}
	for(int i = 0;arr2[i] != '\0';i++){
    	len2++;
	}
    // Comparar los arreglos de caracteres
	if(len1!=len2){
		return false;
	}
    for (int i = 0; i<len1; i++) {
        if (arr1[i] != arr2[i]) {
            equal = false;
            break;
        }
	}
    // Imprimir el resultado
    if (equal) {
        cout << "\t\t\tMateria Registrada" << endl;
        return true;
    } else {
        return false;
    }
    
    
}


//comprobar dia

int obtenerNumeroDia(char* dia) {
    if (dia[0] == 'L' & dia[1] == 'U') {
    	if(dia[2] == 'N' & dia[3] == 'E'){
    		 return 1; // Lunes
		}
    	
       
    } else if (dia[0] == 'M' & dia[1] == 'A') {
        if (dia[2] == 'R' & dia[3] == 'T') {
            return 2; // Martes
        }
    } else if (dia[0] == 'M' & dia[1] == 'I') {
    	if(dia[2]=='E'& dia[3]=='R'){
    		return 3; // Miércoles
		}
            
            
            
    }else if (dia[0] == 'J' & dia[1] == 'U') {
        if (dia[2] == 'E' & dia[3] == 'V') {
            return 4; // Jueves
        } 
    } else if (dia[0] == 'V' & dia[1] == 'I') {
    	if(dia[2]=='E' & dia[3]=='R'){
    		return 5; // Viernes
		}
        
    }else if (dia[0] == 'S' & dia[1] == 'A') {
    	if(dia[2]=='B' & dia[3]=='A'){
    		return 6; // Viernes
		}
        
    }else if (dia[0] == 'D' & dia[1] == 'O') {
    	if(dia[2]=='M' & dia[3]=='I'){
    		return 7; // Viernes
		}
        
    }
    cout<<"Error Ingrese Dia Nuevamente : ";
    cin.getline(dia,25);
    return obtenerNumeroDia(dia);
}




///ARREGLOS PARA DIA LUNES A DOMINGO RESERVAR Y LIBERAR MEMORIA
void inicializarLista(char** lista, int tamLista, int tamPalabra) {
    for (int i = 0; i < tamLista; i++) {
        lista[i] = new char[tamPalabra];
        lista[i][0] = '\0';
    }
}

void liberarLista(char** lista, int tamLista) {
    for (int i = 0; i < tamLista; i++) {
        delete[] lista[i];
    }
    delete[] lista;
}


// comprobar la pocicon de las horas que se van a ingresar a las listas  dias
bool comprobarPosicion(char** lista, int longitud,int posicion){
	if (lista[posicion][0] != '\0' or posicion> longitud) {
        cout<< "Esa posición ya está ocupada. Por favor ingrese otra." << endl;
        return false;
    }else{
    	return true;
	}
}
///formato de horas valido inicio y fin
void horasValidas(int* a , int* b){
	if(*a>*b){
		cout<<"Formato Invalido\n\t Ingresa Hora de Inicio ";
		cin>>*a;
		cout<<"Formato Invalido\n\t Ingresa Hora Final ";
		cin>>*b;
		horasValidas(a,b);
		
		
	}else{
		cout<<"Horas Validas ";
		return ;
	}
}

///funcion ELEGIR HORA INICIO Y FINAL
void seleccionarHoras(int *horaInicio, int *horaFinal) {
    int opcion;
    do {
        cout << "Seleccione Horas\n\t 8-10 [1]\n\t 10-12[2]\n\t 12-14[3]\n\t 14-16[4]\n\t 16-18[5]\n\t Otro[6]\n";
        cin >> opcion;
        switch (opcion) {
            case 1:
                *horaInicio = 8;
                *horaFinal = 10;
                break;
            case 2:
                *horaInicio = 10;
                *horaFinal = 12;
                break;
            case 3:
                *horaInicio = 12;
                *horaFinal = 14;
                break;
            case 4:
                *horaInicio = 14;
                *horaFinal = 16;
                break;
            case 5:
                *horaInicio = 16;
                *horaFinal = 18;
                break;
            case 6:
                cout << "Ingrese la hora inicial: ";
                cin >> *horaInicio;
                cout << "Ingrese la hora final: ";
                cin >> *horaFinal;
                horasValidas(horaInicio, horaFinal);
                break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
                break;
        }
        
    } while (*horaInicio == 0 || *horaFinal == 0);
    
    cout << "Hora inicio: " << *horaInicio << endl;
    cout << "Hora final: " << *horaFinal << endl;
}

///comprobar una pocion en las lista _ _ _
bool posicionesValidas(char** lista___,int* horaI,int* horaF){
	bool flagPosicion=true;
	int copiInicio,copiFinal,posicion;
	while(flagPosicion){
    	flagPosicion = false;
    	copiInicio=*horaI;
    	copiFinal= *horaF;
    	while(copiInicio< copiFinal){
    		posicion=copiInicio;
    		copiInicio++;
    		if(lista___[posicion][0] != '\0'){
    			flagPosicion=true;
			}
    	}
    	if(flagPosicion==true){
    		cout<<"\nEL RANGO DE HORAS YA ESTA OCUPADO\n\t  INGRESE HORAS NUEVAMENTE  :";
    		seleccionarHoras(horaI, horaF);
    		
		}
    	
	}return false;
	
}

///ya se verifico rango d hora entonse se ingresara escribira la materia en el indice dias
void agregarPalabra(char** lista, int longitud , int horaInicio,int horaFinal,char* palabra) {
   posicionesValidas(lista,&horaInicio,&horaFinal);
   while(horaInicio< horaFinal){
   	 // Copiar la palabra en la lista
   	int i = 0;
    while (i < TAM_PALABRA && palabra[i] != '\0') {
        lista[horaInicio][i] = palabra[i];
        i++;
    }
    lista[horaInicio][i] = '\0';
    horaInicio++;
   	
   	
   }
    
}




///





///FUNCION PARA RECIBIR (LISTA DE DIAS 24HORAS) NOMBRE DE MATERIA HORA 
void  ubicarMateriaEnHorario(char** listLUN,char** listMAR,char** listMIE,char** listJUE,char** listVIE,char** listSAB,char** listDOM, char* materia,char* dia){
	int horaInicio=0,horaFinal=0;
	seleccionarHoras(&horaInicio, &horaFinal);
	int indiceDia;//se asigna valor para saber a que list_ _ _  usaremos 
	int opcion;
	bool flagPosicion=true;
	bool flaghorasss=true;
	cout<<endl<<materia<<endl;
	///ubicamos la lista _ _ _ con indiceDia
	indiceDia= obtenerNumeroDia(dia);
	
	///
	switch (indiceDia){
		case 1:
			cout<<"caso 1";
			agregarPalabra(listLUN,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
		case 2:
			cout<<"caso 2";
			while(flaghorasss){
				flaghorasss=posicionesValidas(listMAR,&horaInicio,&horaFinal);
			}
			agregarPalabra(listMAR,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
		case 3:
			cout<<"caso 3";
			while(flaghorasss){
				flaghorasss=posicionesValidas(listMIE,&horaInicio,&horaFinal);
			}
			agregarPalabra(listMIE,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
			
		case 4:
			cout<<"caso 4";
			while(flaghorasss){
				flaghorasss=posicionesValidas(listJUE,&horaInicio,&horaFinal);
			}
			agregarPalabra(listJUE,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
		case 5:
			cout<<"caso 5";
			while(flaghorasss){
				flaghorasss=posicionesValidas(listVIE,&horaInicio,&horaFinal);
			}
			agregarPalabra(listVIE,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
		case 6:
			cout<<"caso 6";
			while(flaghorasss){
				flaghorasss=posicionesValidas(listSAB,&horaInicio,&horaFinal);
			}
			agregarPalabra(listSAB,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
		case 7:
			cout<<"caso 7";
			while(flaghorasss){
				flaghorasss=posicionesValidas(listDOM,&horaInicio,&horaFinal);
			}
			agregarPalabra(listDOM,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
	}
    
    
    /*
    int posicion;
    ///ESPACION DE HORA VALIDAS DISPONIBLE
    while(flagPosicion){
    	flagPosicion = false;
    	copiInicio=horaInicio;
    	copiFinal= horaFinal;
    	while(copiInicio< copiFinal){
    	cout<<copiInicio<<endl;
    	posicion=copiInicio;
    	}
    	
	}
    
    
    
    
    ///se va por las pociciones de inicio hasta fin para cada num escribimos la materia
    while(horaInicio< horaFinal){
    	cout<<horaInicio<<endl;
    	posicion=horaInicio;
    	int i2=0;
    	while (materia[i2] != '\0') {
        listLUN[posicion][i2] = materia[i2];
        i2++;
    	}
    	listLUN[posicion][i2] = '\0';
    	horaInicio++;
	}
    */
    
	
	
	
	
	
	
	
	
	
	cout<<"\n\ncomprobante\n\n";
}
