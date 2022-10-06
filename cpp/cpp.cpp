#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    int max_len = 15;
    int min_len = 3;
    int new_id_len = new_id.size();

    for (int i = 0; i < new_id_len; i++)
    {
        if (new_id[i] == '\0')
            break;

        char temp;
        if (i != 0)
            temp = new_id[i - 1];

        //1. 대문자 -> 소문자 치환
        if (65 <= new_id[i] && new_id[i] <= 90)
        {
            new_id[i] += 32;
            continue;
        }

        //2. 알파벳 소문자, 숫자, 하이픈, 언더바, 마침표 제외하고 제거
        if (!(48 <= new_id[i] && new_id[i] <= 57) &&
            !(97 <= new_id[i] && new_id[i] <= 122) &&
            new_id[i] != 45 && new_id[i] != 95 && new_id[i] != 46)
        {
            new_id.erase(i, 1);
            i--;
            continue;
        }

        //3. 마침표가 두번 이상이면 하나로 치환
        if (i > 0 && (temp == 46 && temp == new_id[i]))
        {
            new_id.erase(i, 1);
            i--;
            continue;
        }

        //4. 마침표가 처음이나 끝에 위치한다면 제거
        if ((i == 0 || i == new_id_len - 1) && new_id[i] == 46)
        {
            new_id.erase(i, 1);
            i--;
            continue;
        }
    }

    //5. 여기까지 해서 new_id 가 빈 문자열이라면 new_id 에 "a"대입
    if (new_id.empty())
    {
        new_id.clear();
        new_id = "a";
    }

    //6. 길이가 16 이상이면 new_id 첫 15개 제외하고 나머지 다 제거
    //다만, 제거 후에 마침표가 new_id의 마지막에 위치한다면, 해당 문자를 제거
    if (new_id.size() > max_len)
        new_id.erase(max_len);

	if (new_id.back() == 46)
		new_id.erase(new_id.size() - 1);

    //7. new_id의 길이가 2자 이하라면 마지막 문자를 자리수가 3이 될때까지 반복한다
	new_id_len = new_id.size();
	for (int i = new_id_len; i < min_len; i++)
	{
		new_id.push_back(new_id[i - 1]);
	}

    string answer = new_id;
    return answer;
}

void main()
{
    //cout << solution("z-+.^.");
    solution("...!@BaT#  * ..y.abcdefghijklm");
}