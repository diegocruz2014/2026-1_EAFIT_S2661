#include <iostream>
#include <limits> // Limipia la entrada en el menú

using namespace std;

// Creación del nodo
struct Node {
    int data;       // Campo de datos
    Node* next;     // Puntero al siguiente nodo (enlace)

    // Constructor: inicializa el dato y el puntero next
    Node(int value) : data(value), next(nullptr) {}
};

// Lista Simplemente Enlazada
class SinglyLinkedList {
private:
    Node* head;     // "inicio" de la lista (puntero)
    Node* tail;     // "fin" de la lista (puntero)
    int lenght;     // "tamaño" de la lista (opcional)

public:
    // Constructor, la lista inicialmente se crea vacía
    SinglyLinkedList() : head(nullptr), tail(nullptr), lenght(0) {}
    
    // Destructor, libera toda la memoria 
    ~SinglyLinkedList() {
        clear(); // Función que borará todos los nodos de la lista
    }
    
    // Función para identificar si la lista está vacía
    bool isEmpty() const {
        return head == nullptr;
    }
    
    // Función para devolver el tamaño de la lista (cantidad de elementos)
    int size() const {
        return lenght;
    }
    
    // Función para mostrar la lista
    void print() const {
        cout << "[ ";
        Node* aux = head; // aux es un nodo temporal que almacena la dirección del primer nodo
        while (aux != nullptr) {    // Recorremos todos los punteros hasta llegar a NULL
            cout << aux->data; // Imprimir el dato del nodo seleccionado
            if (aux->next != nullptr) cout << " -> ";
            aux = aux->next; // Cambiamos el nodo aux al que le sigue
        }
        cout << " ]\n";
        cout << "Cantidad de elementos en la lista: " << size() << endl;
    }
    
    // Limpiar la lista por completo, liberar uno a uno cada nodo
    void clear() {
        Node* aux = head;
        while (aux != nullptr) {
            Node* toDelete = aux; // Guardo el nodo actual
            aux = aux->next; // Avanzo al siguiente nodo antes de borrar
            delete toDelete; // Libero la memoria del nodo
        }
        // En este punto, la lista queda vacía
        head = nullptr;
        tail = nullptr;
        lenght = 0;
    }
    
    /*
    // Función para insertar un elemento en una lista vacía
    void insertIntoEmptyList(int value) {
        // Verificar si la lista no está vacía
        if (!isEmpty()) {
            cout << "Error: La lista no está vacía, utiliza insertar elemento al inicio, al final o en otra parte.\n";
            return;
        }
        
        Node* newNode = new Node(value); // Pasos 1 (asignar memoria ) y 2 (rellenar campo de datos) del algoritmo
        newNode->next = nullptr; // Paso 3 (ya lo hace el constructor)
        
        head = newNode; // Paso 4 (inicio apunta al nuevo)
        tail = newNode; // Paso 4 (fin apunta al nuevo)
        lenght++;       // Paso 5 (actualizar tamaño)
    }
    */
    
    // Función para insertar elemento al inicio de la lista
    void insertHead(int value){
        // Pasos 1 y 2 (asinar memoria y rellenar campo de datos)
        Node* newNode = new Node(value);
        
        // Verificar si la lista está vacía
        if (isEmpty()) {
            // En este caso, insertar al inicio es exactamente igual a insertar
            // un elemento en una lista vacía
            head = newNode;
            tail = newNode;
            lenght++;
            return;
        }
        
        newNode->next = head; // Paso 3
        head = newNode; // Paso 4
        lenght++; // Paso 6
    }
    
    // Función para insertar elemento al final de la lista
    void insertTail(int value){
        // Pasos 1 y 2 (asinar memoria y rellenar campo de datos)
        Node* newNode = new Node(value);
        newNode->next = nullptr; // Corroborar que este nodo apunte a NULL 
        
        // Verificar si la lista está vacía
        if (isEmpty()) {
            // En este caso, insertar al inicio es exactamente igual a insertar
            // un elemento en una lista vacía
            head = newNode;
            tail = newNode;
            lenght++;
            return;
        }
        
        tail->next = newNode; // Paso 3
        tail = newNode; // Paso 4
        lenght++; // Paso 6
    
    }
    
    //insertAfterValue(15, 100);
    
    // Función para insertar un elemento en cualquier parte de la lista
    void insertAfterValue(int key, int valueToInsert){
        // Pasos 1 y 2
        Node* newNode = new Node(valueToInsert); 
        
        // Verificar si la lista está vacía
        if (isEmpty()) {
            // Ejecutar la operación para insertar un nodo en una lista vacía
            head = newNode;
            tail = newNode;
            lenght++;
            return;
        }
        
        // Paso 3
        Node* aux = head;
        while (aux != nullptr && aux->data != key) {
            aux = aux->next;
        }
        
        // Paso 4 
        newNode->next = aux->next;
        
        // Paso 5
        aux->next = newNode;
        
        // Verificar si insertamos un nodo después del último
        if (aux == tail) {
            tail = newNode;
        }
        
        // Paso7: Actualizar el tamaño
        lenght++;
    }

    // Función para buscar un elemento en la lista
    bool search(int value) const {
        Node* aux = head;
        while(aux != nullptr){
            if(aux->data == value) return true;
            aux = aux->next;
        }
        return false;
    }
    
    // Función para eliminar un elemento al inicio de la lista
    void removeHead() {
        // Validar si la lista se encuentra vacía
        if (isEmpty()) {
            cout << "Error. No es posible eliminar un elemento de una lista vacía.\n";
            return;
        }
        
        Node* toDelete = head; // Paso 1 
        head = head->next; // Paso 2 
        lenght--; // Paso 3 
        
        // Liberar memoria eliminando el nodo que ya no se utiliza
        delete toDelete;
    }
    
    // Eliminar el último elemento de la lista
    void removeTail(){
        // Verificar si la lista está vacía
        if (isEmpty()) {
            cout << "Error: No es posible elimiar un elmento de una lista vacía." << endl;
            return;
        }
        
        // Paso 1: guardar en un nodo temporal el elemento a eliminar
        Node* toDelete = tail; 
        
        // Paso 2: encontrar el elemento actual (el que quedará antes del que se elimina)
        Node* aux = head;
        while (aux->next != tail) {
            aux = aux->next;
        }
        
        // Paso 3:
        aux->next = tail->next;
        
        // Paso 4:
        tail = aux;
        
        // Paso 5:
        lenght--;
        
        // Liberar memoria
        delete toDelete;
    }

};




// Función principal
int main()
{
    // Crear la lista enlazada 
    SinglyLinkedList lista;
    
    int op;
    do {
        cout << "\nLISTA SIMPLEMENTE ENLAZADA\n";
        cout << "1. Insertar elemento al inicio de la lista\n";
        cout << "2. Insertar elemento al final de la lista\n";
        cout << "3. Insertar elemento en cualquier parte de la lista\n";
        cout << "4. Eliminar el primer elemento de la lista\n";
        cout << "5. Eliminar el último elemento de la lista\n";
        cout << "6. Buscar un elemento de la lista\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> op;
        
        int valor, clave;
        switch(op) {
            case 1:
                cout << "Valor a insertar al inicio de la lista: ";
                cin >> valor;
                // Ejecutar la operación en la lista enlazada
                lista.insertHead(valor);
                lista.print();
                break;
            case 2:
                cout << "Valor a insertar al final de la lista: ";
                cin >> valor;
                // Ejecutar la operación en la lista enlazada
                lista.insertTail(valor);
                lista.print();
                break;
            case 3:
                cout << "Insertar después de (key): ";
                cin >> clave;
                cout << "Valor a insertar: ";
                cin >> valor;
                // Ejecutar la operación en la lista enlazada
                lista.insertAfterValue(clave, valor);
                lista.print();
                break;
            case 4:
                lista.removeHead();
                lista.print();
                break;
            case 5:
                lista.removeTail();
                lista.print();
                break;
            case 6:
                cout << "Escriba el número a buscar: ";
                cin >> valor;
                if (lista.search(valor)) {
                    cout << "El número " << valor << " si se encuentra en la lista" << endl;
                }
                else {
                    cout << "El número " << valor << " no se encuentra en la lista" << endl;
                }
                lista.print();
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