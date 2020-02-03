//Function Pointers
//Printing the Value of a Vector

void PrintValue(int value){
    std::cout << "Value" << value<< std::endl
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
    std::cout <<Value:"<<value<<std::endl;  
    }  
}
