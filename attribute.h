#include <string>


using namespace std;

class attribute{
	private:
		string action;
		string id;
		float number;
		
		
	public:
		attribute(){
			action = "NULL";
			id = "NULL"
			number = 0.0;
		}
		attribute(string act, string iden, float num){
			action = act;
			id = iden;
			number = num;
		}
		attribute(string act, float num){
			action = act;
			number = num;
		}
		float eval(string a, float num1, float num2);
		
};
