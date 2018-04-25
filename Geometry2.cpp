#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <map>
using namespace std;
//Definimos la clase Point con dos variables privadas x e y
//3 POINT(Geometry.h)
class Point {
    private:
	int x, y;
	//Definimos los metodos de la glase de tipo Set y Get,
	//Le asignamos valores predeterminados en el constructor a nuestras variables
public :
	Point (int xx =0, int yy =0) {x = xx; y = yy ;}
	int getX () const { return x;}
	int getY () const { return y;}
	void setX ( const int xx) {x = xx ;}
	void setY ( const int yy) {y = yy ;}
};
//4 POINT ARRAY(Geometry.h)
//Definimos la CLASE PointArray
class PointArray {
    //Las variables de la clase seran size(tamaño) y un array de elementos Point(points).
int size ;
Point * points ;
//el metodo resize modificara la variable size.
void resize (int size );
//Definimos nuestros metodos y constructores.
public :
//En este caso tenemos 4 constructores:
//El constructor predeterminado.
PointArray ();
//El constructor de Copia, crea una copia de un PointArray.
PointArray ( const Point pts [], const int size );
//El constructor de Memoria, impide que los dos Point array ocupen un mismo espacio de Memoria.
PointArray ( const PointArray &pv);
//Destructor que eliminara la matriz interna PointArray.
~ PointArray ();
void clear ();
int getSize () const { return size ;}
//El metodo push_back desplazara a l aderecha todos los elementos para colocar el elmento que se desea al comienzo.
void push_back ( const Point &p);
//El metodo insert añadira un elemento en una posicion indicada.
void insert ( const int pos , const Point &p);
//El metodo remove eliminara un elemento en una posicion indicada.
void remove ( const int pos );
Point *get( const int pos);
// Se llamara a un elemento de la matriz de puntos, si la posicion de ese elmento supera el rango del array
//devolverá un puntero nulo.
const Point *get( const int pos) const ;
};
PointArray :: PointArray () {
	size = 0;
	points = new Point [0]; // Allows deleting later
}

PointArray :: PointArray ( const Point ptsToCopy [], const int toCopySize) {
	size = toCopySize ;
	points = new Point [ toCopySize ];
	for(int i = 0; i < toCopySize ; ++i) {
		points [i] = ptsToCopy [i];
	}
}

PointArray :: PointArray ( const PointArray & other ) {
	// Any code in the PointArray class has access to
	// private variables like size and points
	size = other . size ;
	points = new Point [ size ];
	for (int i = 0; i < size ; i++) {
		points [i] = other . points [i];
	}
}

PointArray ::~ PointArray () {
    //El nombre siempre va despues de los corchetes en el destructor;
	delete [] points ;
}

void PointArray :: resize ( int newSize ) {
    //Reservamos un espacio de memoria para nuestro arreglo de puntos.
	Point *pts = new Point [ newSize ];
	// si nuestra variable size es menor que newSize entonces el valor de min size sera newSize
	int minSize = ( newSize > size ? size : newSize );
	//Posteriormente se copia los elementos de pts a points.
	for (int i = 0; i < minSize ; i++)
		pts[i] = points [i];
    //siempre se coloca delete[] despues de cada new.
	delete [] points ;
	//el valor de size es newSize ahora.
	size = newSize ;
	//Actualiza la lista points por la pts que posee un tamaño menor al anterior
	points = pts ;
}

void PointArray :: clear () {
    //formatea el tamaño
	resize (0) ;
}

void PointArray :: push_back ( const Point &p) {
	resize ( size + 1);
	points [ size - 1] = p;
	// Could also just use insert (size , p);
}

void PointArray :: insert ( const int pos , const Point &p) {
    //Se aumenta en 1 el tamño original
	resize ( size + 1);
   // Realizamos una lectura de la posicion del elemento en la posicion p.
	for (int i = size - 1; i > pos; i --) {
            //Posteriormente los elementos se adelantan y el espacio sobrante es donde sera insertado el nuevo elemento.
		points [i] = points [i -1];
	}

	points [pos ] = p;
}

void PointArray :: remove ( const int pos ) {
	if( pos >= 0 && pos < size ) { // pos < size implies size > 0
	// Shift everything over to the left
	//Se recorre desde la posicion del elemnto que se desea eliminar hasta el tamaño-2
	//para posteriormente cambiar los elemntos por el que esta una posicion mas adelante
		for(int i = pos; i < size - 2; i++) {
			points [i] = points [i + 1];
		}
		//y disminuir en uno el tamaño del arreglo
		resize ( size - 1);
	}
}

Point * PointArray :: get( const int pos) {
	return pos >= 0 && pos < size ? points + pos : NULL ;
}

const Point * PointArray :: get( const int pos) const {
	return pos >= 0 && pos < size ? points + pos : NULL ;
}

//geometry.h
//Se declara la clase Polygon
class Polygon {
protected :
    //Esta clase poseera una variable estatica entera llamada numPolygons y un arreglo de elementos Point
        static int numPolygons ;
        PointArray points ;
//Se declaran los metodos,constructores y destructores de Polygon.
public :
    //El constructor uno hara un paso por refencia de un arreglo de punteros
    Polygon ( const PointArray &pa);
    //El otro constructor creara un poligono a partir de un array de Points Y el tamaño de dicho array
    Polygon ( const Point points [], const int numPoints );
    //El metodo area se declara;
    virtual double area () const = 0;
    //El metodo getNumPolygons retorna el numero de Polygons
    static int getNumPolygons () { return numPolygons ;}
    //El metodo getNumSides retorna el numero de lados
    int getNumSides () const { return points.getSize () ;}
    //El metodo getPoints retorna un puntero inmodificable
    const PointArray * getPoints () const { return & points ;}
    //Destructor
    ~ Polygon () {-- numPolygons ;}
 };

 //geometry.cpp
int Polygon::numPolygons = 0;

Polygon :: Polygon ( const PointArray &pa) : points (pa) {
    ++ numPolygons ;
 }

Polygon :: Polygon ( const Point pointArr [], const int numPoints ) :
    points ( pointArr , numPoints ) {
    ++ numPolygons ;
 }
 //Se define la clase Rectangle con Herencia de Polygon
class Rectangle : public Polygon {
public :
    // Se tomaran dos puntos para construir un rectangulo el punto de la esquina inferior izquierda y la superior derecha
    Rectangle ( const Point &a, const Point &b);
    //Constructor de un rectangulo de 4 entradas
    Rectangle ( const int a, const int b, const int c, const int d);
    virtual double area () const ;
};


//geometry.cpp
//se deline un array de 4 elementos para dar forama al rectangulo
Point constructorPoints [4];
//hace el paso de referencia actrualizando los puntos de construccion
Point * updateConstructorPoints ( const Point &p1 , const Point &p2 ,
    const Point &p3 , const Point &p4 = Point (0 ,0)) {
     constructorPoints [0] = p1;
     constructorPoints [1] = p2;
     constructorPoints [2] = p3;
     constructorPoints [3] = p4;
     return constructorPoints ;
 }
//Se definen las coordenadas de las 2 esquinas
Rectangle :: Rectangle ( const Point &ll , const Point &ur)
 : Polygon ( updateConstructorPoints (ll , Point (ll. getX () , ur. getY ()
),
                                      ur , Point (ur. getX () , ll. getY ()
                                          )), 4) {}
//se definen los puntos de creacion del rectangulo
Rectangle :: Rectangle ( const int llx , const int lly , const int urx ,
    const int ury)
 : Polygon ( updateConstructorPoints ( Point (llx , lly), Point (llx ,
    ury),
                                       Point (urx , ury), Point (urx ,
                                      lly)), 4) {}
//el metodo area retorna la multtiplicacion del largo por el ancho.
 double Rectangle :: area () const {
     //Se definen estas dos dimensiones por medio de coordenadas ingresando a los metodos getX y getY de cada Point
     int length = points .get (1) ->getY () - points .get (0) ->getY ();
     int width = points .get (2) ->getX () - points .get (1) ->getX ();
     //Correccion
     return std::abs(length*width);
 }
 //Se define la clase triangulo
 //Lo mismo sucede en la clase triangulo se heredaran caracteristicas de la clase polygon
class Triangle : public Polygon {
public :
    //El constructor poseera tres arguentos que seran los 3 puntos que daran forma a nuestro triangulo
    Triangle ( const Point &a, const Point &b, const Point &c);
    virtual double area () const ;
};
//el constructor se define con la caracteristica de polygons updateConstructorPoints que actualizaran los valores de cada punto
Triangle :: Triangle ( const Point &a, const Point &b, const Point &c)
: Polygon ( updateConstructorPoints (a, b, c), 3) {}
//Se realizan llamadas a los metodos GetX y GetY de cada Point
 double Triangle :: area () const {
    int dx01 = points .get (0) ->getX () - points .get (1) ->getX () ,
        dx12 = points .get (1) ->getX () - points .get (2) ->getX () ,
        dx20 = points .get (2) ->getX () - points .get (0) ->getX ();
    int dy01 = points .get (0) ->getY () - points .get (1) ->getY () ,
        dy12 = points .get (1) ->getY () - points .get (2) ->getY () ,
        dy20 = points .get (2) ->getY () - points .get (0) ->getY ();
        //Se realizan las operaciones para realizar la fórmula de Heron;
    double a = std :: sqrt ( dx01 * dx01 + dy01 * dy01 ),
           b = std :: sqrt ( dx12 * dx12 + dy12 * dy12 ),
           c = std :: sqrt ( dx20 * dx20 + dy20 * dy20 );

    double s = (a + b + c) / 2;
    //Y dan como resultado el area del triangulo
    return std :: sqrt ( s * (s-a) * (s-b) * (s-c) );
 }
 //4.- TEMPLATE STACK:
 // CREAMOS UN TEMPLATE PARA LA CALSE STACK
 template < class T> class Stack ;
 template < class T>
 //EN ESTE TEMPALTE SOBRECARGAMOS EL OPERADOR +;
 Stack <T> operator +( const Stack <T> & s1 , const Stack <T> & s2 )
    {     Stack<T> result = s1;
         // EL CONTENIDO DE LA PILA RESULT(ESTA POSEE LOS MISMOS ELEMENTOS QUE POSEE S1.
          for ( unsigned i = 0; i < s1 . items . size (); ++ i) {
                //LOS EMPUJAMOS PARA ATRAS CON EL METODO PUSH_BACK Y AGREGAMOS LOS ELEMENTOS DE LA PILA S2.
             result.items.push_back(s2 .items [ i]);
        }
           return result ;
   }
//PARA MOSTRAR NUESTRA PILA
//SOBRECARGAMOS EL OPERADOR <<;
//SIEMPRE CREANDO UN TEMPLADE PARA LA CLASE STACK;

template < class T>
ostream&operator <<(ostream &output, Stack<T> &p1)
{
    for(int i=0;i<p1.items.size();i++)
    {
        output<<p1.items[i];
    }
}

 template < class T>
 //DEFINIMOS LA CLASE STACK CON UN TEMPLATE.
 class Stack {
     // CREAMOS UNA FUNCION FRIEND SOBRECARGANDO EL OPERADOR +;
     // LOS ELEMENTOS DE LA PILA SON DE TIPO VECTOR.
     public:
           friend Stack < T> operator +<>( const Stack <T> & s1 , const Stack <T> & s2 );
           vector<T>items;
           //EL METODO EMPTY DEVUELVE SI LA PILA ESTA VACIA.
 public :
           bool empty () const { return items.empty () ;}
           //EL METODO PUSH INSERTA ELEMENTOS.
           void push ( const T & item ) { items . push_back ( item );}
           //EL METODO POP ELIMINA EL ULTIMO ELEMENTO DE LA PILA.
           T pop () {
           T last = items . back ();
           items . pop_back ();
           return last ;
            }
            //EL METODO TOP DEVUELVE EL ULTIMO ELEMENTO DE LA PILA.
           T top(){

                T last=items.back();
                return last;
           }
  };
class Graph {
  protected :
  map <int,vector < int > > outgoing ;
  public :
  Graph(const vector<int>&startPoints,const vector<int>&endPoints );
  int numOutgoing ( const int nodeID ) const ;
  const vector < int > & adjacent ( const int nodeID ) const ;
 };
Graph :: Graph ( const vector < int > & startPoints , const vector < int > & endPoints ) {
    if( startPoints . size () != endPoints . size ()) {
    throw invalid_argument (" Start / end point lists differ in length ");
    }
 for ( unsigned i = 0; i < startPoints . size (); i++ ) {
    int start = startPoints [ i], end = endPoints [ i];
    outgoing [ start ]. push_back ( end );
    outgoing [ end ]; // Just to indicate this node exists
}
 }

 //Este procedimiento imprimira los atributos de un poligono
 void printAttributes ( Polygon *p) {
    cout << "p’s area is " << p-> area () << ".\n";
    cout << "p’s points are :\n";
    const PointArray *pa = p-> getPoints ();
    for(int i = 0; i < pa -> getSize (); ++i) {
        cout << "(" << pa ->get (i) ->getX () << ", " << pa ->get (i) ->getY () << ")\n";
    }}
int main()
{
    Point punto;
    int cx=4;
    int cy=5;
    punto.setX(cx);
    punto.setY(cy);
    /*cout<<"LAS COORDENADAS DEL PUNTO SON "<<punto.getX()<<","<<punto.getY()<<endl;
    //
    cout << " Enter lower left and upper right coords of rectangle as four space separated integers : ";
    int llx , lly , urx , ury;
    cin >> llx >> lly >> urx >> ury;
    Point ll(llx , lly), ur(urx , ury);
    Rectangle r(ll , ur);
    printAttributes (&r);
    cout << " Enter three coords of triangle as six space separated integers : ";
    int x1 , y1 , x2 , y2 , x3 , y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point a(x1 , y1), b(x2 , y2), c(x3 , y3);
    Triangle t(a, b, c);
    printAttributes (&t);*/
    //4 CLASS STACK
    Stack<int>pila;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    for(int i=0;i<pila.items.size();i++)
    {
        cout<<pila.items[i]<<" ";
    }
    cout<<endl;
    if(pila.empty()==true)
    {
        cout<<"Esta vacia"<<endl;
    }
    else
    {
        cout<<"No esta vacia"<<endl;
    }
    cout<<"El ultimo elemento es "<<pila.top()<<endl;

}
