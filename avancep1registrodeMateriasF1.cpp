#include<iostream>
#include <fstream>
using namespace std;

void vaciararreglo(char* list);

void agregarMateriaLista();

void materiastxt(char* arr);

void materiaMayus(char* materia);

bool arrIguales(char* arr1,char*arr2);

int obtenerNumeroDia(char* dia);

int main(){
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
    for(int i = 0 ; i< numeroMaterias;i++){
    	cout<<listaMaterias[0][i]<<endl;
	}
    
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
        
    }
    cout<<"Error Ingrese Dia Nuevamente : ";
    cin.getline(dia,25);
    return obtenerNumeroDia(dia);
}
