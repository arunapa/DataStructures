#include <iostream>
#include <string>

using std::string;

int isBalanced(string a){
	string stack;
	int i = 0, j = 0;
	while(a[i] != '\0'){
		if(a[i] == '{' || a[i] == '[' || a[i] == '('){
			stack.push_back(a[i]);
			//std::cout << stack << std::endl;
			j++;
		}
		else if(a[i] == '}' || a[i] == ']' || a[i] == ')'){
			
			if(stack.empty()){
				return i;
			}
				
			if(a[i] == '}' && stack.back() != '{')
				return i;
				
			if(a[i] == ']' && stack.back() != '[')
				return i;
				
			if(a[i] == ')' && stack.back() != '(')
				return i;
			//std::cout << stack.back() << "\n";
			stack.pop_back();
			//std::cout << stack << std::endl;
			}
		i++;
	}
	if(stack.empty() == true)
		return 1;
	else
		return i - 1;
}

int main(){
	string a;
	std::cin >> a;
	int i = isBalanced(a);
	if(i == 1)
		std::cout << "Success";
	else
		std::cout << i + 1;
	return 0;
}
