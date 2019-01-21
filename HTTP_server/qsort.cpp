#include<windows.h>
#include<iostream.h>
#include<fstream.h>

void dosort(int * t,int l,int r);
int dmidPos(int l,int r)
{
	return l+1*(r-l)/2;
}
void qsort(LPVOID a,int l,int r)
{
	int size=r-l+1;

	int *t=(int *)a;//指针转化
	if(l>=r)return;
	if(size>2000)
	{
		int midPos=dmidPos(l,r);

		int waitor=t[midPos];
		t[midPos]=t[l];//从最左端开始
		int i=l,j=r;
		while(true)
		{

			while(i<j&&waitor<=t[j])
			{
				j--;
			}
			if(i==j)
				break;
			t[i++]=t[j];
			while(i<j&&t[i]<=waitor)
			{
				i++;
			}
			if(i==j)
				break;
			t[j--]=t[i];
		}
		t[i]=waitor;
		//在接下来的化分开的两部分用两个进程来排序
		STARTUPINFO startInfo1,startInfo2;
		PROCESS_INFORMATION procInfo1,procInfo2;
		ZeroMemory(&startInfo1,sizeof(startInfo1));
		startInfo1.cb=sizeof(startInfo1);
		ZeroMemory(&startInfo2,sizeof(startInfo2));
		startInfo2.cb=sizeof(startInfo2);

		char cmdLine1[20],buf1[10],cmdLine2[20],buf2[10];
		memset(cmdLine1,0,sizeof(cmdLine1));
		memset(cmdLine2,0,sizeof(cmdLine2));
		_itoa(l,cmdLine1,10);
		cmdLine1[strlen(cmdLine1)]=' ';
		strcat(cmdLine1,_itoa(i-1,buf1,10));
//	    cout<<"l="<<l<<" i-1="<<i-1<<endl;
//	    cout<<"cmdLine1="<<cmdLine1<<endl;
		_itoa(i+1,cmdLine2,10);
		cmdLine2[strlen(cmdLine2)]=' ';
		strcat(cmdLine2,_itoa(r,buf2,10));
//		cout<<"i+1="<<i+1<<" r="<<r<<endl;
//	    cout<<"cmdLine2="<<cmdLine2<<endl;
		//Sleep(1000);
		if(i-1>l)
		{
			
			if(!CreateProcess(
				"./Debug/qsort.exe",
				cmdLine1,
				NULL,
				NULL,
				true,
				NORMAL_PRIORITY_CLASS,
				NULL,
				NULL,
				&startInfo1,
				&procInfo1
				))
			{
				cout<<"CreateProcess1 falt!"<<endl;
			};
			WaitForSingleObject(procInfo1.hProcess,INFINITE);
		}
		if(i+1<r)
		{
			if(!CreateProcess(
				"./Debug/qsort.exe",
				cmdLine2,
				NULL,
				NULL,
				true,
				NORMAL_PRIORITY_CLASS,
				NULL,
				NULL,
				&startInfo2,
				&procInfo2
				))
			{
				cout<<"CreateProcess2 falt!"<<endl;
			};
			WaitForSingleObject(procInfo2.hProcess,INFINITE);
		}
		//产生两个新的进程 来进行快速排序
		
		
	}
	else//直接用该进程进行快速排序
	{
		dosort(t,l,r);
	}
}

void dosort(int * t,int l,int r)
{
	if(l>=r)return;
	if(r-l<32)//如果数据规模过小 则用直接排序
	{
		for(int j=l+1;j<=r;j++)
		{
			for(int i=j-1;i>=l;i--)
			{
				if(t[j]>=t[i])break;
			}
			int k=j,temp=t[j];
			while(k>i+1)
			{
				t[k]=t[k-1];
				k--;
			}
			t[i+1]=temp;
		}
	}
	else //否则用快速排序 
	{
		int midPos=dmidPos(l,r);
		int waitor=t[midPos];
		t[midPos]=t[l];//从最左端开始
		int i=l,j=r;
		while(true)
		{
			while(i<j&&waitor<=t[j])
			{
				j--;
			}
			if(i==j)
				break;
			t[i++]=t[j];
			while(i<j&&t[i]<=waitor)
			{
				i++;
			}
			if(i==j)
				break;
			t[j--]=t[i];
		}
		t[i]=waitor;
		dosort(t,l,i-1);
		dosort(t,i+1,r);
	}
}

void landValue(char * c,int & l,int & r)
{
	int i=0;
	int len=strlen(c);
	l=r=0;
	for(;i<len;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
			l=l*10+(c[i]-'0');
		else break;
	}
	i++;
	for(;i<len;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
			r=r*10+(c[i]-'0');
			else break;
	}
	if(l>r)
	{
		cout<<"CMDLINE VALUE 有误！"<<endl;
		return;
	}
}
void main(int argc, char *argv[])
{
	
	HANDLE hFileMap=OpenFileMapping(FILE_MAP_ALL_ACCESS,true,"field");
	LPINT lpMapAddress=(LPINT)MapViewOfFile(//打开之后用MapViewOfFile建立该文件到本进程地址空间的映射
		hFileMap,							// handle to file-mapping object
		FILE_MAP_ALL_ACCESS,				// access mode
		0, //DWORD dwFileOffsetHigh,		// high-order DWORD of offset
		0, //DWORD dwFileOffsetLow,			// low-order DWORD of offset 
		0  //SIZE_T dwNumberOfBytesToMap    // number of bytes to map
		);
	char *cmdLine=GetCommandLine();
	int l,r;
	landValue(cmdLine,l,r);
	qsort((int *)lpMapAddress,l,r);
}

