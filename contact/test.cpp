#include"contect.h"





void menu()
{
	
	cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�["<<endl;
	cout << "�U�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T  ͨѶ¼  �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�U"<<endl;
	cout << "�U�T�T�T                                             �T�T�T�U" << endl;
	cout << "�U�T�T�T           1.�½�           2.ɾ��           �T�T�T�U"<<endl;
	cout << "�U�T�T�T           3.����           4.�޸�           �T�T�T�U"<<endl;
	cout << "�U�T�T�T           5.���           6.����           �T�T�T�U"<<endl;
	cout << "�U�T�T�T           7.��ӡ           0.�˳�           �T�T�T�U"<<endl;
	cout << "�U�T�T�T                                             �T�T�T�U" << endl;
	cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a"<<endl;
}





void test()
{
	
	system("color c"); //�ı䱳��
	Contact my_con;
	InitContact(&my_con);

	int input = 0;

	do
	{
	
		menu();
		cout << "��ѡ��";
		cin >> input;

		switch (input)
		{
		case Exit:
			break;

		case Add:
			AddContact(&my_con);
			break;

		case Del:
			DelContact(&my_con);
			break;

		case Search:
			SearchContact(&my_con);
			break;
			
		case Modify:
			ModifyContact(&my_con);
			break;

		case Empty:
			EmptyContact(&my_con);
			break;

		case Sort:
			SortContact(&my_con);
			break;

		case Show:
			ShowContact(&my_con);
			break;
		default:
			cout << "ѡ�����->!!!" << endl;
			break;
		}



	} while (input);
}




int main()
{
	test();
	return 0;
}