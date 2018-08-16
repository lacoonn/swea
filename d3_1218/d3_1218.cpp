#include <iostream>
#include <vector>

using namespace std;

char str[1000];
string input_string;
vector<char> stack;

int main()
{
	int caseCount = 1;

	do
	{
		int result = 1;
		int input_length;

		cin >> input_length;

		////////////////////////////////////////////////////////////////////////////////////////////

		cin >> str;

		for (int i = 0; i < input_length; i++) {
			if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<') {
				stack.push_back(str[i]);
			}
			else if (str[i] == ')') {
				if (stack.back() == '(') {
					stack.pop_back();
				}
				else {
					result = 0;
					break;
				}
			}
			else if (str[i] == ']') {
				if (stack.back() == '[') {
					stack.pop_back();
				}
				else {
					result = 0;
					break;
				}
			}
			else if (str[i] == '}') {
				if (stack.back() == '{') {
					stack.pop_back();
				}
				else {
					result = 0;
					break;
				}
			}
			else if (str[i] == '>') {
				if (stack.back() == '<') {
					stack.pop_back();
				}
				else {
					result = 0;
					break;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////

		cout << "#" << caseCount++ << " " << result << endl;
	} while (caseCount <= 10);

    return 0;
}

