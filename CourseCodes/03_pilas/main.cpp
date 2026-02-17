#include <iostream>

using namespace std;

// Creación del nodo
struct Node {
    string data;       // Campo de datos
    Node* next;     // Puntero al siguiente nodo (enlace)

    // Constructor: inicializa el dato y el puntero next
    Node(string value) : data(value), next(nullptr) {}
};

// Pila
class Stack {
private:
    Node* head;     // "inicio" de la pila (puntero)
    Node* top;     // "fin" de la pila (puntero)
    int lenght;     // "tamaño" de la lista (opcional)

public:
    // Constructor, la lista inicialmente se crea vacía
    Stack() : head(nullptr), top(nullptr), lenght(0) {}
    
    // Destructor, libera toda la memoria 
    ~Stack() {
        clear(); // Función que borará todos los nodos de la lista
    }
    
    // Función para identificar si la pila está vacía
    bool isEmpty() const {
        return top == nullptr;
    }
    
    // Función para devolver el tamaño de la lista (cantidad de elementos)
    int size() const {
        return lenght;
    }
    
    // Función para mostrar la pila
    void print() const {
        cout << "[ ";
        Node* aux = head; // aux es un nodo temporal que almacena la dirección del primer nodo
        while (aux != nullptr) {    // Recorremos todos los punteros hasta llegar a NULL
            cout << aux->data << endl; // Imprimir el dato del nodo seleccionado
            if (aux->next != nullptr) cout << " -> ";
            aux = aux->next; // Cambiamos el nodo aux al que le sigue
        }
        cout << " ]\n";
        cout << "Cantidad de elementos en la pila: " << size() << endl;
    }
    
    // Limpiar la pila por completo, liberar uno a uno cada nodo
    void clear() {
        Node* aux = head;
        while (aux != nullptr) {
            Node* toDelete = aux; // Guardo el nodo actual
            aux = aux->next; // Avanzo al siguiente nodo antes de borrar
            delete toDelete; // Libero la memoria del nodo
        }
        // En este punto, la pila queda vacía
        head = nullptr;
        top = nullptr;
        lenght = 0;
    }
    
    // Función para mostrar la cima de la pila 
    string Top() const {
        return top->data;
    }
    
    // Función para apilar elementos
    void push(string value){
        // Pasos 1 y 2 (asinar memoria y rellenar campo de datos)
        Node* newNode = new Node(value);
        newNode->next = nullptr; // Corroborar que este nodo apunte a NULL 
        
        // Verificar si la lista está vacía
        if (isEmpty()) {
            // En este caso, insertar al inicio es exactamente igual a insertar
            // un elemento en una lista vacía
            head = newNode;
            top = newNode;
            lenght++;
            return;
        }
        
        top->next = newNode; // Paso 3
        top = newNode; // Paso 4
        lenght++; // Paso 6
    
    }
    
    // Función para desapilar elementos
    string pop(){
        // Verificar si la pila está vacía
        if (isEmpty()) {
            return "Error: No es posible elimiar un elmento de una pila vacía.\n";
        }
        
        // Paso 1: guardar en un nodo temporal el elemento a eliminar
        Node* toDelete = top; 
        
        // Paso 2: encontrar el elemento actual (el que quedará antes del que se elimina)
        Node* aux = head;
        while (aux->next != top) {
            aux = aux->next;
        }
        
        // Paso 3:
        aux->next = top->next;
        
        // Paso 4:
        top = aux;
        
        // Paso 5:
        lenght--;
        
        // Entrego a la aplicación el nodo eliminado
        string valueDeleted = toDelete->data;
        delete toDelete; // Limpiar memoria
        return valueDeleted;
    }
  
};


int main()
{
    // Crear la lista enlazada 
    Stack deshacer, rehacer;
    
    int op;
    do {
        cout << "\nPILA\n";
        cout << "Acciones en un procesador de texto\n";
        cout << "Seleccione la opción:\n";
        cout << "1. Escribir acción\n";
        cout << "2. Deshacer\n";
        cout << "3. Rehacer\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> op;
        
        string valor;
        switch(op) {
            case 1:
                cout << "Escriba la acción a realizar: ";
                cin >> valor;
                // Ejecutar la operación en la lista enlazada
                deshacer.push(valor);
                deshacer.print();
                break;
            
            case 0:
                cout << "\nPrograma finalizado\n";
                break;
            default:
                cout << "\nOpción inválida.\n";
        }
    
    } while (op != 0);
    
    return 0;
}