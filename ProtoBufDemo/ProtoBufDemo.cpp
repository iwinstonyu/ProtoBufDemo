// ProtoBufDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "msginfo.pb.h"
using namespace std;

#pragma comment (lib, "libprotobufd.lib")
#pragma comment (lib, "libprotobuf-lited.lib")
#pragma comment (lib, "libprotocd.lib")

int main()
{
	cout << "hello world" << endl;

	msginfo::CMsgLogin msgLogin;
	msgLogin.set_ret(1);
	string str;
	msgLogin.SerializeToString(&str);

	cout << "msgLogin typeName: " << msgLogin.GetTypeName() << endl;

	msginfo::CMsgLogin msgRecv;
	msgRecv.ParseFromString(str);

	cout << msgRecv.ret() << endl;

	msginfo::CMsgReg msgReg;
	msgReg.set_area(1);
	msgReg.set_region(1);
	msgReg.set_shop(1);
	msgReg.set_ret(1);
	string strDebug = msgReg.DebugString();

	cout << "DebugString: " << endl;
	cout << msgReg.DebugString() << endl;

	cout << "ShortDebugString: " << endl;
	cout << msgReg.ShortDebugString() << endl;

	string oneLine = msgReg.DebugString();
	replace(oneLine.begin(), oneLine.end(), '\n', ' ');
	//boost::replace_all(oneLine, "\n", " ");
	cout << "OneLine: " << endl;
	cout << oneLine << endl;

	string strMsg;
	::google::protobuf::Message* pMsg = &msgRecv;
	try
	{
		pMsg->SerializeToString(&strMsg);
	}
	catch (google::protobuf::FatalException)
	{
		return 0;
	}

	cout << "base msg typeName: " << pMsg->GetTypeName() << endl;

	//cout << "msbbase: " << msgBase.GetTypeName() << endl;


	system("pause");

    return 0;
}

