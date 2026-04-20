#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Creación de la estructura Nodo
struct Nodo {
    int dato;
    Nodo* izq; // Puntero para el lado izquierdo
    Nodo* der; // Puntero para el lado derecho
    
    // Constructor
    Nodo(int valor) {
        dato = valor;
        izq = nullptr;
        der = nullptr;
    }
};

class ArbolBinario {
private:
    Nodo* raiz;
    
    // Función para insertar un nodo
    Nodo* insertarNodo(Nodo* nodo, int valor) {
        // Si no hay nodo, se crea
        if (nodo == nullptr) {
            return new Nodo(valor);
        }
        
        // Recursividad para localizar el lugar de inserción
        // del nodo
        if (valor < nodo->dato) {
            nodo->izq = insertarNodo(nodo->izq, valor);
        } 
        else {
            nodo->der = insertarNodo(nodo->der, valor);
        }
        
        return nodo;
    }
    
    // Buscar un nodo
    bool buscarNodo(Nodo* nodo, int valor) {
        // Si al recorrer el árbol no hay nodo, entonces no se 
        // encuentra el elemento
        if (nodo == nullptr) {
            return false;
        }
        
        // Confirmar si se encuentra el valor
        if (valor == nodo->dato) {
            return true;
        }
        
        // Recursividad para recorrer el árbol buscando el elemento
        if (valor < nodo->dato) {
            return buscarNodo(nodo->izq, valor);
        }
        else {
            return buscarNodo(nodo->der, valor);
        }
    }
    
    // Recorrido en preorden
    void preordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            cout << nodo->dato << " ";  // Visitar la raiz
            preordenRec(nodo->izq);     // Atravesar el subarbol izquierdo
            preordenRec(nodo->der);     // Atravesar el subarbol derecho
        }
    }
    
    // Recorrido inorden
    void inordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            inordenRec(nodo->izq);
            cout << nodo->dato << " ";
            inordenRec(nodo->der);
        }
    }
    
    // Recorrido postorden
    void postordenRec(Nodo* nodo) {
        if (nodo != nullptr) {
            postordenRec(nodo->izq);
            postordenRec(nodo->der);
            cout << nodo->dato << " ";
        }
    }
    
    // Altura del árbol
    int alturaRec(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        
        int altIzq = alturaRec(nodo->izq);
        int altDer = alturaRec(nodo->der);
        
        return 1 + max(altIzq, altDer);
    }
    
    // Encontrar el valor mínimo
    Nodo* minimoRec(Nodo* nodo) {
        while (nodo != nullptr && nodo->izq != nullptr) {
            nodo = nodo->izq;
        }
        return nodo;
    }
    
    // Encontrar el valor mínimo
    Nodo* maximoRec(Nodo* nodo) {
        while (nodo != nullptr && nodo->der != nullptr) {
            nodo = nodo->der;
        }
        return nodo;
    }
    
    // Método para eliminar un nodo con un valor específico
    Nodo* eliminarRec(Nodo* nodo, int valor) {
        // Verificar que el árbol no esté vacío
        if (nodo == nullptr) {
            return nullptr;
        }
        
        if (valor < nodo->dato) {
            nodo->izq = eliminarRec(nodo->izq, valor);
        }
        else if (valor > nodo->dato) {
            nodo->der = eliminarRec(nodo->der, valor);
        }
        else {
            if (nodo->izq == nullptr && nodo->der == nullptr) {
                delete nodo;
                return nullptr;
            }
            
            if (nodo->izq == nullptr) {
                Nodo* temp = nodo->der;
                delete nodo;
                return temp;
            }
            
            if (nodo->der == nullptr) {
                Nodo* temp = nodo->izq;
                delete nodo;
                return temp;
            }
            
            Nodo* sucesor = minimoRec(nodo->der);
            nodo->dato = sucesor->dato;
            nodo->der = eliminarRec(nodo->der, sucesor->dato);
            
            
        }
        
        return nodo;
    }
    
    // Método para liberar el árbol
    void liberarRec(Nodo* nodo) {
        if(nodo != nullptr) {
            liberarRec(nodo->izq);
            liberarRec(nodo->der);
            delete nodo;
        }
    }
    
    
public:
    // Constructor
    ArbolBinario() {
        raiz = nullptr;
    }
    
    // Destructor
    ~ArbolBinario() {
        liberarRec(raiz);
    } 
    
    void insertar(int valor) {
        raiz = insertarNodo(raiz, valor);
    }
    
    bool buscar(int valor) {
        return buscarNodo(raiz, valor);
    }
    
    void preorden() {
        preordenRec(raiz);
        cout << endl;
    }
    
    void inorden() {
        inordenRec(raiz);
        cout << endl;
    }
    
    void postorden() {
        postordenRec(raiz);
        cout << endl;
    }
    
    int altura() {
        return alturaRec(raiz);
    }
    
    int minimo() {
        Nodo* nodoMin = minimoRec(raiz);
        if (nodoMin == nullptr) {
            throw runtime_error("El árbol está vacío");
        }
        return nodoMin->dato;
    }
    
    int maximo() {
        Nodo* nodoMax = maximoRec(raiz);
        if (nodoMax == nullptr) {
            throw runtime_error("El árbol está vacío");
        }
        return nodoMax->dato;
    }
    
    void eliminar(int valor) {
        raiz = eliminarRec(raiz, valor);
    }
};


// Método principal
int main()
{
    // Crear árbol
    ArbolBinario arbol;
    
    // Ingresar datos al arbol
    arbol.insertar(50);
    arbol.insertar(2026);
    arbol.insertar(4);
    arbol.insertar(17);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    
    // Recorrer el árbol
    cout << "Recorrido preorden:\n";
    arbol.preorden();
    
    cout << "\nRecorrido inorden:\n";
    arbol.inorden();
    
    cout << "\nRecorrido postorden:\n";
    arbol.postorden();
    
    cout << "\nAltura: " << arbol.altura() << endl;
    cout << "Buscar 40: " << (arbol.buscar(40) ? "Si" : "No") << endl;
    cout << "Mínimo: " << arbol.minimo() << endl;
    cout << "Máximo: " << arbol.maximo() << endl;
    
    arbol.eliminar(50);
    
    cout << "Inorden después de eliminar 30: ";
    arbol.inorden();
    
    return 0;
}