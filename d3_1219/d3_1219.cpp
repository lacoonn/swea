#include <iostream>

using namespace std;

int path[100][2];

int find_path(int current) {
	int result;

	if (current == 99) {
		return 1;
	}
	else if (path[current][0] == -1 && path[current][1] == -1) {
		return 0;
	}
	else {
		if (path[current][0] != -1) {
			result = find_path(path[current][0]);
		}
		if (result == 0 && path[current][1] != -1) {
			result = find_path(path[current][1]);
		}
		return result;
	}
}

int main()
{
	int caseCount = 1;

	do
	{
		int result = -1;
		int path_size;

		cin >> caseCount;
		cin >> path_size;

		////////////////////////////////////////////////////////////////////////////////////////////
		// 배열 초기화
		for (int i = 0; i < 100; i++) {
			path[i][0] = -1;
			path[i][1] = -1;
		}
		// 배열 입력
		for (int i = 0; i < path_size; i++) {
			int from, to;
			cin >> from >> to;
			if (path[from][0] == -1) {
				path[from][0] = to;
			}
			else {
				path[from][1] = to;
			}
		}
		// 계산
		result = find_path(0);

		////////////////////////////////////////////////////////////////////////////////////////////

		cout << "#" << caseCount++ << " " << result << endl;
	} while (caseCount < 11);

    return 0;
}