#include<iostream>
#include <fstream>
using namespace std;

void vaciararreglo(char* list);

void agregarMateriaLista();

int materiastxt(char* arr);

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

void agregarDormir(char** lista, int longitud , int horaInicio,int horaFinal,char* palabra);

//void  ubicarMateriaEnHorario(char** list, char* materia);
void  ubicarMateriaEnHorario(char** listLUN,char** listMAR,char** listMIE,char** listJUE,char** listVIE,char** listSAB,char** listDOM, char* materia,char* dia );

void imprimirTodo(char** listaDia,int TAM_LISTA);

void liberarLista(char** lista, int tamLista);

void imprimirHORARIO(char** listLUN,char** listMAR,char** listMIE,char** listJUE,char** listVIE,char** listSAB,char** listDOM,int TAM_LISTA);

int espacioVacios(char** listaDia,int TAM_LISTA);

int listaConMasVacios(char** listLUNES,char** listMARTES,char** listMIERCOLES,char** listJUEVES,char** listVIERNES,char** listSABADO,char** listDOMINGO);

int contarPalabra(char* palabra);

void agregarNVeces(char** lista,int veces, int TAM_PALABRA,int TAM_LISTA,char* palabra);

void escribirPalabraEnLista(char** listL, char** listMA, char** listMI, char** listJ, char** listV, char** listS, char** listDOM, int faltantes, char* palabra);

void mainpr();

void mainpr(){
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
	int horaInicioSueno=0,horaFinalSueno=7;
	char sueno[TAM_PALABRA] ="DORMIR";
	agregarDormir(listaLUN,TAM_LISTA ,horaInicioSueno,horaFinalSueno,sueno);
	agregarDormir(listaMAR,TAM_LISTA ,horaInicioSueno,horaFinalSueno,sueno);
	agregarDormir(listaMIE,TAM_LISTA ,horaInicioSueno,horaFinalSueno,sueno);
	agregarDormir(listaJUE,TAM_LISTA ,horaInicioSueno,horaFinalSueno,sueno);
	agregarDormir(listaVIE,TAM_LISTA ,horaInicioSueno,horaFinalSueno,sueno);
	agregarDormir(listaSAB,TAM_LISTA ,horaInicioSueno,horaFinalSueno,sueno);
	agregarDormir(listaDOM,TAM_LISTA ,horaInicioSueno,horaFinalSueno,sueno);
	
	
	///
	
	//DANGER
	char matDias[1][3][100];//dias para el ciclo de pedir horario de hora se guardaran los dias
	//PENDIENTE VACIAS A MATDIAS POSIBLE ERROR 
    char name[100];
    int  numeroMaterias;
    cout<<"INGRESA TU NAME: ";
    cin.getline(name,100);
    materiaMayus(name);
    cout<<"HI ";
    for(int i =0; name[i]!='\0'; i++){
        cout<<name[i];
    }
    vaciararreglo(name);
    for(int i =0; name[i]!='\0'; i++){
        cout<<name[i];
    }
    cout<<"\nINGRESA NUMERO DE MATERIAS: ";
    cin>> numeroMaterias;
    int listaCreditos[numeroMaterias];
    char materia[100];
    vaciararreglo(materia);
    char listaMaterias[1][numeroMaterias][100];
    cin.ignore();//Ignorar el salto de linea pendiente despues de la entrada anterior
    int credito;
    for(int i = 0 ; i < numeroMaterias ; i++){
        cout<<"\t\tPOR FAVOR INGRESA MATERIA "<< ":\t";
        vaciararreglo(listaMaterias[0][i]);
        cin.getline(listaMaterias[0][i],100); // permitir espacios al ingresar la materia
        credito = materiastxt(listaMaterias[0][i]);
        listaCreditos[i]=credito;
    }
    // IMPRIMIR MATERIAS MI PEZ
    cout<<"SE REGISTRARON TUS MATERIAS:\n\n";
    for(int cr = 0 ; cr < numeroMaterias;cr++){
    	
    	cout<<listaCreditos[cr];
	}
    for(int iii = 0 ; iii< numeroMaterias;iii++){
    	contarPalabra(listaMaterias[0][iii]);
    	cout<<"\n\n _________________\n";
    	cout<<"||  "<<listaMaterias[0][iii]<<"  ||"<<endl;
    	cout<<" _________________\n\n";
    	
    	
    	int numDias,opcionMatReg;
		int indicadorDiaList;
		cout<<"INGRESA DATOS DE MATERIA\n\t   DIAS:\n\t\tMartes-Jueves[1]\n\t\tMiercoles - Viernes[2]\n\t\tHorario Diferente [3]\n";
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
			cout<<"INGRESA NUMERO DE DIAS: ";
			cin>>numDias;
			cin.ignore();
			char matDias[1][3][100]={{"", "", ""}};;
			for(int i = 0; i < numDias ;i++){
				cout<<"\nINGRESA DIA:  ";
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
    
	}
	//PRUEBA DE IMPRESION
	for(int ii = 0 ; ii < numeroMaterias;ii++){
		cout<<listaMaterias[0][ii]<<"  CREDITOS ";
		cout<<listaCreditos[ii]<<endl;
    
	}
   	
	cout<<"\n	 LUNES   MARTES   MIERCOLES	 JUEVES   VIERNES";
	cout<<"	SABADO  DOMINGO\n";
	imprimirHORARIO(listaLUN,listaMAR, listaMIE, listaJUE, listaVIE, listaSAB, listaDOM, TAM_LISTA);
	int horasTotalCreditos=0;
	for(int cr = 0 ; cr < numeroMaterias;cr++){
		cout<<(listaCreditos[cr]*48)/16<<endl;
    	horasTotalCreditos+=(listaCreditos[cr]*48)/16;
	}
	cout<<horasTotalCreditos;
	cout<<endl;
	int horasvaciasss=0;
	int horasDeEstudio=0;
	horasvaciasss+=espacioVacios(listaLUN, TAM_LISTA);
	horasvaciasss+=espacioVacios(listaMAR, TAM_LISTA);
	horasvaciasss+=espacioVacios(listaMIE, TAM_LISTA);
	horasvaciasss+=espacioVacios(listaJUE, TAM_LISTA);
	horasvaciasss+=espacioVacios(listaVIE, TAM_LISTA);
	horasvaciasss+=espacioVacios(listaSAB, TAM_LISTA);
	horasvaciasss+=espacioVacios(listaDOM, TAM_LISTA);
	
	horasDeEstudio=119-horasvaciasss;
	cout<<"TUS HORAS DE ESTUDIO SON: "<<horasDeEstudio;
	cout<<"  TE HACEN FALTA :   "<<horasTotalCreditos-horasDeEstudio<<endl<<endl;
	int opcionAcabarTodo;
	cout<<"  ::: DESEAS QUE COMPLETE TU HORARIO ::: "<<endl;
	cout<<"\t  PARA AUTOCOMPLETAR [1]\n\t  PARA HACERLO MANUAL INGRESA [2]\n";
	cout<<"\t  DEJAR ASI [3]";
	cin>>opcionAcabarTodo;
	while(opcionAcabarTodo>3 or opcionAcabarTodo<0 ){
		cout<<"INGRESA OPCION VALIDA ";
		cin>>opcionAcabarTodo;
		
	}
	
	if(opcionAcabarTodo==1){
		for(int i = 0 ,horasRec=0,horasFaltan,horasRegis; i <numeroMaterias; i++){
			cout<<listaMaterias[0][i]<<"  "<<listaCreditos[i]<<endl;
			horasRec=(listaCreditos[i]*3);
			//cout<<horasRec<<endl;
			horasRegis=contarPalabra(listaMaterias[0][i]);
			horasFaltan=horasRec-horasRegis;
			//cout<<"horas faltante  "<<horasFaltan<<endl;
			escribirPalabraEnLista(listaLUN,listaMAR,listaMIE,listaJUE,listaVIE,listaSAB,listaDOM,horasFaltan,listaMaterias[0][i]);
		 
	}
	}else if(opcionAcabarTodo==2){
		
	}
	
	cout<<endl;
	cout<<"	 LUNES   MARTES   MIERCOLES	 JUEVES   VIERNES";
	cout<<"	SABADO  DOMINGO\n";
	imprimirHORARIO(listaLUN,listaMAR, listaMIE, listaJUE, listaVIE, listaSAB, listaDOM, TAM_LISTA);
	for(int ii = 0 ; ii < numeroMaterias;ii++){
		cout<<listaMaterias[0][ii]<<"  CREDITOS ";
		cout<<listaCreditos[ii]<<endl;
    
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
    
    
    return ;
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
int materiastxt(char* list) {
    char arr[100];
    int i = 0;
    bool materiaEsta = false;
    char credito;
    
    // Abrir el archivo
    ifstream file("Materias.txt");
    materiaMayus(list);
    
    while (file.is_open() && !materiaEsta) {
        // Leer línea por línea
        while (!file.eof() && !materiaEsta) {
            // Leer la línea
            char line[100];
            vaciararreglo(arr);
            file.getline(line, 100);
            
            
            // Recorrer la línea hasta la coma
            for (int j = 0; line[j] != ',' && line[j] != '\0'; j++) {
                arr[i++] = line[j];
                credito=line[j+2];
            }
            // Agregar un caracter nulo al final del arreglo
            arr[i] = '\0';
            
            // Imprimir el arreglo resultante
            materiaEsta = arrIguales(list, arr);
            
            if (materiaEsta) {
            	cout<<"CREDITOS "<<credito<<endl;
                file.close();
                return (credito -48);
            }
            
            // Reiniciar el contador
            i = 0;
        }
        
        // Verificar si se llego al final del archivo y la materia aun no se ha encontrado
        if (file.eof() && !materiaEsta) {
            cout << "\t\t\tMATERIA NO ENCONTRADA, INGRESA UNA MATERIA VALIDA: ";
            cin.getline(list, 100);
            materiaMayus(list);
            file.clear();  // Limpiar los indicadores de error del archivo
            file.seekg(0); // Reiniciar la posicion de lectura del archivo al principio
        }
    }
    
    // Cerrar el archivo
    
    file.close();
    return credito -48;
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
        cout << "\t\t\tMATERIAS REGISTRADA\n" << endl;
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
    cout<<"ERROR INGRESE DIA NUEVAMENTE: ";
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
        cout<< "POSION OCUPADA POR FAVOR INGRESE NUEVAMENTE." << endl;
        return false;
    }else{
    	return true;
	}
}
///formato de horas valido inicio y fin
void horasValidas(int* a , int* b){
	if(*a>*b or *b >23 or *a< 0){
		cout<<"Formato Invalido\n\t Ingresa Hora de Inicio ";
		cin>>*a;
		cout<<"Formato Invalido\n\t Ingresa Hora Final ";
		cin>>*b;
		horasValidas(a,b);
		
		
	}else{
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

///dormir
void agregarDormir(char** lista, int longitud , int horaInicio,int horaFinal,char* palabra) {
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
			agregarPalabra(listMAR,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
		case 3:
			cout<<"caso 3";
			agregarPalabra(listMIE,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
			
		case 4:
			cout<<"caso 4";
			agregarPalabra(listJUE,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
		case 5:
			cout<<"caso 5";
			agregarPalabra(listVIE,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
		case 6:
			cout<<"caso 6";
			agregarPalabra(listSAB,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
		case 7:
			cout<<"caso 7";
			agregarPalabra(listDOM,TAM_LISTA ,horaInicio,horaFinal,materia);
			break;
	}
	cout<<"\n\ncomprobante\n\n";
}



// IMPRIMIR LISTA DIA L_M_M_J......
void imprimirTodo(char** listaDia,int TAM_LISTA){
    
    
	 for (int i = 0; i < TAM_LISTA; i++) {
        cout << "Posición " << i << ":";
        if (listaDia[i][0] == '\0') {
            cout << "______";
        } else {
            cout << listaDia[i];
        }
        cout << endl;
    }
}


void imprimirHORARIO(char** listLUN,char** listMAR,char** listMIE,char** listJUE,char** listVIE,char** listSAB,char** listDOM,int TAM_LISTA){
	 ofstream archivo("RR35.txt"); // abrir el archivo en modo ESCRITURA
	 if (archivo.is_open()) {
    } else {
        cout << "No se pudo abrir el archivo" << std::endl;
    }	
	 for (int i = 0; i < TAM_LISTA; i++) {
        cout << "HORA : " << i << ":";
        if (listLUN[i][0] == '\0') {
            cout << "___________   ";
        } else {
            cout << listLUN[i]<<"   ";
            archivo<<listLUN[i]<<endl;
            
        }
        if (listMAR[i][0] == '\0') {
            cout << "__________   ";
        } else {
            cout << listMAR[i]<<"   ";
            archivo<<listMAR[i]<<endl;
            
        }
        if (listMIE[i][0] == '\0') {
            cout << "__________   ";
        } else {
            cout << listMIE[i]<<"   ";
            archivo<<listMIE[i]<<endl;
            
        }
        if (listJUE[i][0] == '\0') {
            cout << "__________   ";
        } else {
            cout << listJUE[i]<<"   ";
            archivo<<listJUE[i]<<endl;
            
        }
        if (listVIE[i][0] == '\0') {
            cout << "__________   ";
        } else { 
            cout << listVIE[i]<<"   ";
            archivo<<listVIE[i]<<endl;
            
        }
        if (listSAB[i][0] == '\0') {
            cout << "__________   ";
        } else {
            cout << listSAB[i]<<"   ";
            archivo<<listSAB[i]<<endl;
            
        }
        if (listDOM[i][0] == '\0') {
            cout << "__________   ";
        } else {
            cout << listDOM[i]<<"   ";
            archivo<<listDOM[i]<<endl;
            
        }
        cout << endl;
    }
    archivo.close();
    
}


// CANTOR ESPACIOS DE LISTA

int espacioVacios(char** listaDia,int TAM_LISTA){
	int vacios=0;
	 for (int i = 0; i < TAM_LISTA; i++) {
        if (listaDia[i][0] == '\0') {
        	vacios++;
        } 
    }
    return vacios;
}
///veces que esta materia en horario;
int  contarPalabra(char* palabra) {
    ifstream archivo("RR35.txt");
    if (archivo) {
        int contador = 0;
        char linea[100];
        while (archivo.getline(linea, 100)) {
            int i = 0, j = 0;
            bool coincidencia = true;
            while (palabra[i] != '\0' && linea[j] != '\0') {
                if (palabra[i] != linea[j]) {
                    coincidencia = false;
                    break;
                }
                i++;
                j++;
            }
            if (coincidencia && palabra[i] == '\0') {
                contador++;
            }
        }
        archivo.close();
        return contador;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return -1;
        
    }
}

///funcion para encontrar la lista de dias con mas vacios
int listaConMasVacios(char** listLUNES,char** listMARTES,char** listMIERCOLES,char** listJUEVES,char** listVIERNES,char** listSABADO,char** listDOMINGO) {
    int masVacios = 0;
    int diaMasVacios = 0;
    int vacios;

    vacios = espacioVacios(listLUNES, 24);
    if (vacios > masVacios) {
        masVacios = vacios;
        diaMasVacios = 1;
    }

    vacios = espacioVacios(listMARTES, 24);
    if (vacios > masVacios) {
        masVacios = vacios;
        diaMasVacios = 2;
    }

    vacios = espacioVacios(listMIERCOLES, 24);
    if (vacios > masVacios) {
        masVacios = vacios;
        diaMasVacios = 3;
    }

    vacios = espacioVacios(listJUEVES, 24);
    if (vacios > masVacios) {
        masVacios = vacios;
        diaMasVacios = 4;
    }

    vacios = espacioVacios(listVIERNES, 24);
    if (vacios > masVacios) {
        masVacios = vacios;
        diaMasVacios = 5;
    }

    vacios = espacioVacios(listSABADO, 24);
    if (vacios > masVacios) {
        masVacios = vacios;
        diaMasVacios = 6;
    }

    vacios = espacioVacios(listDOMINGO, 24);
    if (vacios > masVacios) {
        masVacios = vacios;
        diaMasVacios = 7;
    }

    return diaMasVacios;
}



void agregarNVeces(char** lista,int veces, int TAM_PALABRA,int TAM_LISTA,char* palabra) {
   int contador=0;
   for(int i =0; contador<veces and i < TAM_LISTA;i++){
   	if(lista[i][0]=='\0'){
   		contador++;
   		agregarDormir(lista, TAM_LISTA ,i,i+1,palabra);
   		
	   }
   }
   	
}

//agregar veces faltantes
void escribirPalabraEnLista(char** listLUNES, char** listMARTES, char** listMIERCOLES, char** listJUEVES, char** listVIERNES, char** listSABADO, char** listDOMINGO, int faltantes, char* palabra) {
    int espaciosTodasListas=0;
    espaciosTodasListas+=espacioVacios(listLUNES, TAM_LISTA);
	espaciosTodasListas+=espacioVacios(listMARTES, TAM_LISTA);
	espaciosTodasListas+=espacioVacios(listMIERCOLES, TAM_LISTA);
	espaciosTodasListas+=espacioVacios(listJUEVES, TAM_LISTA);
	espaciosTodasListas+=espacioVacios(listVIERNES, TAM_LISTA);
	espaciosTodasListas+=espacioVacios(listSABADO, TAM_LISTA);
	espaciosTodasListas+=espacioVacios(listDOMINGO, TAM_LISTA);
	if(espaciosTodasListas<faltantes){
		cout<<"HERMANO CANCELE ALGO  "<<endl;
		return ;
	}
    int indiceListaMasVacios=0;
	int vacios=0;
    
    while (faltantes > 0) {
    	indiceListaMasVacios = listaConMasVacios(listLUNES, listMARTES, listMIERCOLES, listJUEVES, listVIERNES, listSABADO, listDOMINGO);
    	switch (indiceListaMasVacios) {
                case 1:
                    vacios= espacioVacios(listLUNES, TAM_LISTA);
                    if(vacios>=faltantes){
                    	agregarNVeces(listLUNES,faltantes,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=0;
                    	
					}else if(faltantes>vacios){
						agregarNVeces(listLUNES,vacios,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=faltantes-vacios;
						
					}
                    break;
                case 2:
                	vacios= espacioVacios(listMARTES, TAM_LISTA);
                    if(vacios>=faltantes){
                    	agregarNVeces(listMARTES,faltantes,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=0;
                    	
					}else if(faltantes>vacios){
						agregarNVeces(listMARTES,vacios,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=faltantes-vacios;
						
					}
                    
                    break;
                case 3:vacios= espacioVacios(listMIERCOLES, TAM_LISTA);
                    if(vacios>=faltantes){
                    	agregarNVeces(listMIERCOLES,faltantes,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=0;
                    	
					}else if(faltantes>vacios){
						agregarNVeces(listMIERCOLES,vacios,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=faltantes-vacios;
						
					}
                    
                    break;
                case 4:
                	vacios= espacioVacios(listJUEVES, TAM_LISTA);
                    if(vacios>=faltantes){
                    	agregarNVeces(listJUEVES,faltantes,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=0;
                    	
					}else if(faltantes>vacios){
						agregarNVeces(listJUEVES,vacios,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=faltantes-vacios;
						
					}
                    
                    break;
                case 5:
                	vacios= espacioVacios(listVIERNES, TAM_LISTA);
                    if(vacios>=faltantes){
                    	agregarNVeces(listVIERNES,faltantes,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=0;
                    	
					}else if(faltantes>vacios){
						agregarNVeces(listVIERNES,vacios,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=faltantes-vacios;
						
					}
                    
                    break;
                case 6:
                	vacios= espacioVacios(listSABADO, TAM_LISTA);
                    if(vacios>=faltantes){
                    	agregarNVeces(listSABADO,faltantes,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=0;
                    	
					}else if(faltantes>vacios){
						agregarNVeces(listSABADO,vacios,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=faltantes-vacios;
						
					}
                    
                    break;
                case 7:
                	vacios= espacioVacios(listDOMINGO, TAM_LISTA);
                    if(vacios>=faltantes){
                    	agregarNVeces(listDOMINGO,faltantes,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=0;
                    	
					}else if(faltantes>vacios){
						agregarNVeces(listDOMINGO,vacios,TAM_PALABRA,TAM_LISTA,palabra);
                    	faltantes=faltantes-vacios;
					}
                    break;
            }
        
        }
        return;
    
}