#include "Main.h"

int check(std::string path)
{

	return access(path.c_str(),0);

}

int check2(std::string path)
{
	
	if (access(path.c_str(),0) == -1)
	{
		std::cout<< "360壁纸没有安装\n";
	}
	else
	{
		//std::cout<< "检测到360壁纸!\n";
		
		if(rmdir(path.c_str()) == 0)
		{
			std::cout<< "删除成功！\n";	
		}
		else
	    {
			std::cout<< "删除失败\n";
		}
	}	
	
	return 0;

}

void DeleteFiles(std::string dir) {
	//在目录后面加上"\\*.*"进行第一次搜索
	std::string newDir = dir + "\\*.*";
	//用于查找的句柄
	intptr_t handle;
	struct _finddata_t fileinfo;
	//第一次查找
	handle = _findfirst(newDir.c_str(), &fileinfo);
 
	if (handle == -1) {
		std::cout <<  "无文件" << std::endl;
		system("pause");
		return;
	}
 
	do
	{
		if (fileinfo.attrib & _A_SUBDIR) {//如果为文件夹，加上文件夹路径，再次遍历
			if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0)
				continue;
 
			// 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
			newDir = dir + "\\" + fileinfo.name;
			DeleteFiles(newDir.c_str());//先遍历删除文件夹下的文件，再删除空的文件夹
			std::cout << newDir.c_str() << std::endl;
			if (_rmdir(newDir.c_str()) == 0) {//删除空文件夹
				std::cout <<  "删除文件成功!" << std::endl;
			}
			else {
				std::cout <<  "删除文件失败!" << std::endl;
			}
		}
		else{
			std::string file_path = dir + "\\" + fileinfo.name;
			std::cout << file_path.c_str() << std::endl;
			if (remove(file_path.c_str()) == 0) {//删除文件
				std::cout <<  "删除成功!" << std::endl;
			}else{
				std::cout <<  "删除失败!" << std::endl;
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
    
    std::cout<< "欢迎来到360壁纸杀手！\n";
    std::cout<< "请在下方输入你最初给计算机命名的名称，一般情况下为Administrator\n";
    std::cout<< "你的计算机名称:";
    
    std::cin>>inputt;
    
    file = "C:/Users/"+inputt+"/AppData/Roaming/360HuaBao";
    
	if(check(file) == -1)
	{
		std::cout<< "360壁纸没有安装"<<std::endl;
	}
	else
	{
		std::cout<< "检测到360壁纸!"<<std::endl;
		
		system("pause");
		
		DeleteFiles(file);
		
		system("pause");
		
		if(check2(file) == 0 )
		{
			std::cout<< "删除成功\n";
		}
		else
		{
			std::cout<< "删除失败\n";
		}	
		
	}
	
	system("pause");
	return 0;

}

