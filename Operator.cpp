//addition von Komplexen Zahlen
class Complex
{
public:
	Complex() = default;
	~Complex() = default;
	int re, im;
  
	Complex& operator + (Complex const &obj) {
		Complex res;
		res.re = re + obj.re;
		res.im = im + obj.im;
		return res;
	}
	//Operator << als friend definiert da die funktion außerhalb stehen muss und dadurch zugriff auf private hat
	friend std::ostream& operator<<(std::ostream& out, const Complex& toOut);
	//Operator << als friend definiert aus selben gründen wie >>
	friend std::istream& operator>>(std::istream& in, Complex& toIn);
};

//Operator << overloaded damit er "re+im'i'"ausgibt
std::ostream& operator<<(std::ostream& out, const Complex& toOut) {
	return out << toOut.re << "+" << toOut.im << "i";

}

std::istream& operator>>(std::istream& in, Complex& toIn) {
	 std::cin>> toIn.a >> toIn.b;
	//Cin.clear und cin.ignore damit sie bei einem erneuten aufrufen keinen error auslösen. der error würde wegen i zu int entstehen
	 std::cin.clear();
	 std::cin.ignore(1000, '\n');
	 return in;
}

// main
int main(){
Complex x, y, w;
	x.a = 5; 	x.b = 3;
	y.a = 4;	y.b = 6;
	//Testing operator+
	Complex z = x + y;
	
	//Testing Operator <<
	std::cout << z << std::endl;
	//Testing Operator >>, eingabe "8+7i" ist möglich
 	std::cin >> w;
  return 0;
}
  
  
