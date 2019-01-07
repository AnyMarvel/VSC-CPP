#include <string>
#include <json/json.h>
#include <iostream>
#include <fstream>
#include <Language.h>
using namespace std;
using namespace coustom;
void readFileJson(); //从文件中读取JSON，一个存储了JSON格式字符串的文件

int main(int argc, char *argv[])
{
    coustom::Language::Get()->init("lang/chinese.json");

    LANG_FORMAT("ShortVariableNameRuleMsg","中国", "名称","s");
    // readFileJson();

    return 0;
}

//从文件中读取JSON
void readFileJson()
{
    Json::Reader reader;
    Json::Value root;

    //从文件中读取，保证当前文件有test.json文件
    ifstream in("lang/chinese.json", ios::binary);
    //in.open("test.json", ios::binary);

    if (!in.is_open())
    {
        cout << "Error opening file\n";
        return;
    }

    /*
	//test.json内容如下：
	{
		"name":"Tsybius",
		"age":23,
		"sex_is_male":true,
		"partner":
		{
			"partner_name":"Galatea",
			"partner_age":21,
			"partner_sex_is_male":false
		},
		"achievement":["ach1","ach2","ach3"]
	}
	*/

    if (reader.parse(in, root))
    {
        int versionName = root["version"].asInt();
        cout << "version" + std::to_string(versionName) << endl;

        for (unsigned int i = 0; i < root["strings"].size(); i++)
        {

            string k = root["strings"][i]["k"].asString();
            cout << k << endl;
            string v = root["strings"][i]["v"].asString();
            cout << v << endl;
        }
    }
    else
    {
        cout << "parse error\n"
             << endl;
    }

    in.close();
}
