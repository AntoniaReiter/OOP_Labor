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
};

//in main
int main(){
Complex x, y;
	x.a = 5; 	x.b = 3;
	y.a = 4;	y.b = 6;
	Complex z = x + y;
  
  return 0;
}
  
  
