#include "Main.h"

int check(std::string path)
{

	return access(path.c_str(),0);

}

int check2(std::string path)
{
	
	if (access(path.c_str(),0) == -1)
	{
		std::cout<<"360��ֽû�а�װ\n";
	}
	else
	{
		std::cout<<"��⵽360��ֽ!\n";
		
		if(rmdir(path.c_str()) == 0)
		{
			std::cout<<"ɾ���ɹ���\n";	
		}
		else
	    {
			std::cout<<"ɾ��ʧ��\n";
		}
	}	
	
	return 0;

}

void DeleteFiles(std::string dir) {
	//��Ŀ¼�������"\\*.*"���е�һ������
	std::string newDir = dir + "\\*.*";
	//���ڲ��ҵľ��
	intptr_t handle;
	struct _finddata_t fileinfo;
	//��һ�β���
	handle = _findfirst(newDir.c_str(), &fileinfo);
 
	if (handle == -1) {
		std::cout << "���ļ�" << std::endl;
		system("pause");
		return;
	}
 
	do
	{
		if (fileinfo.attrib & _A_SUBDIR) {//���Ϊ�ļ��У������ļ���·�����ٴα���
			if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0)
				continue;
 
			// ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
			newDir = dir + "\\" + fileinfo.name;
			DeleteFiles(newDir.c_str());//�ȱ���ɾ���ļ����µ��ļ�����ɾ���յ��ļ���
			std::cout << newDir.c_str() << std::endl;
			if (_rmdir(newDir.c_str()) == 0) {//ɾ�����ļ���
				std::cout << "ɾ���ļ��ɹ�!" << std::endl;
			}
			else {
				std::cout << "ɾ���ļ�ʧ��!" << std::endl;
			}
		}
		else{
			std::string file_path = dir + "\\" + fileinfo.name;
			std::cout << file_path.c_str() << std::endl;
			if (remove(file_path.c_str()) == 0) {//ɾ���ļ�
				std::cout << "ɾ���ɹ�!" << std::endl;
			}else{
				std::cout << "ɾ��ʧ��!" << std::endl;
			}
		}
	} while (!_findnext(handle, &fileinfo));
 
	_findclose(handle);
	return;
}

int main()
{
    std::string file;
    std::string inputt;
    
    std::cout<<"��ӭ����360��ֽɱ�֣�\n";
    std::cout<<"�����·��������������������������ƣ�һ�������ΪAdministrator\n";
    std::cout<<"��ļ��������:";
    
    std::cin>>inputt;
    
    file = "C:/Users/"+inputt+"/AppData/Roaming/360HuaBao";
    
	if(check(file) == -1)
	{
		std::cout<<"360��ֽû�а�װ"<<std::endl;
	}
	else
	{
		DeleteFiles(file);
		
		system("pause");
		
		if(check2(file) == 0 )
		{
			std::cout<<"ɾ���ɹ�\n";
		}
		else
		{
			std::cout<<"ɾ��ʧ��\n";
		}	
		
	}
	
	system("pause");
	return 0;
}


