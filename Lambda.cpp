/*
Aufbau Lambda [capture](params)
[] -> was ich in die funktion geben soll 
        [=] -> wert wird hineingegeben
        [&] -> referenz wird hinein gegeben
        [variabel] -> eine Variable wird übernommen
        
*/


//Function Pointers
//Printing the Value of a Vector

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

