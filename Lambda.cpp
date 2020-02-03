/*
Aufbau Lambda [capture](params)
[] -> was ich in die funktion geben soll 
        [=] -> wert wird hineingegeben
        [&] -> referenz wird hinein gegeben
        [variabel] -> eine Variable wird übernommen
        
*/


//Function Pointers
//Printing the Value of a Vector


#include <algorithm>



void PrintValue(int value){
    std::cout << "Value" << value<< std::endl;
}
    
    //Aufruf der Funktion ForEach, es wird der Vektor übergeben und ein function pointer auf PrintValue
void ForEach(const std::vector<int>& values, void(*func)(int)) {
    for(int value:values)
        func(value); //Es wird value vom vector an die funktion PrintValue übergeben
}

int main(){
    std::vector<int> values = {1, 5, 4, 2, 3 };
    ForEach(values, PrintValue); //Aufruf von ForEach mit übergabe der Funktion
    
}

#Mit Lambda ersetzt-> lambda ist eine annonyme funktion



    
    //Aufruf der Funktion ForEach, es wird der Vektor übergeben und ein function pointer auf PrintValue
void ForEach(const std::vector<int>& values, void(*func)(int)) {
    for(int value:values)
        func(value); //Es wird value vom vector an die funktion PrintValue übergeben
}

int main(){
    std::vector<int> values = {1, 5, 4, 2, 3 };
    //Aufruf der Lambda funktion 
    //mit den []werden die variablen übergeben
    ForEach(values, [])(int value){
    std::cout <<"Value:"<<value<<std::endl;  
    }  
}

//oder

    
    //Aufruf der Funktion ForEach, es wird der Vektor übergeben und ein function pointer auf PrintValue
void ForEach(const std::vector<int>& values, const std::function<void(*func)(int)>& func) {
    for(int value:values)
        func(value); 
}
int main(){
    std::vector<int> values = {1, 5, 4, 2, 3 };
    int a=5;
    //Aufruf der Lambda funktion 
    //mit den []werden die variablen übergeben
    ForEach[](int value){
    std::cout <<Value:"<<value<<std::endl;  
    }  
}



// Funktioniert: Lambda sume
std::vector<int> values = { 1,2,3,4,5,6,7,8,9 };
auto sum = [](auto vec) {
        int sum = 0;
        for (auto& n : vec) {
                sum += n;
        }
        return sum;
};

std::cout << "sum: " << sum(values) << "\n";
              //den wert um je 1 erhöhen und erneut ausgeben
std::for_each(values.begin(), values.end(), [](auto &val) {val++; });
	
	std::cout << "Sum: " << sum(values) << "\n";
