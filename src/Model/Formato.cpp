#include "Formato.hpp"


Formato::Formato(char const *dir){
	srand(time(NULL)); // Inicia o gerador de numeros aleatorios com uma seed (tempo atual)
	std::ifstream MyReadFile(dir);
	std::string line;
	std::vector<std::vector<bool>> format;
	std::vector<bool> format_line;
	this->names = {'I','J','L','O','S','T','Z'};
	formatos.push_back(std::vector<std::vector<bool>> (1, std::vector<bool>(0, 0)));
	int ii=0;
	int jj=0;
	int kk=0;
	while (getline(MyReadFile, line)) {
 	 // Output the text from the file
 		 if(line.length() == 0){
		 	//this->formatos.push_back(format);
			ii++;
			jj = 0;
			formatos.push_back(std::vector<std::vector<bool>> (1, std::vector<bool>(1, 0)));
		 }
		 else{
			formatos[ii].push_back(std::vector<bool>(line.length(), 0));
			if(jj == 0) formatos[ii].erase(formatos[ii].begin());
		 	for(int i=0; i<line.length(); i++){
				formatos[ii][jj][i] =  (line[i]=='1');
			}
			jj++;
		 }

	}
	MyReadFile.close();
}


std::vector<std::vector<bool>> Formato::get_random(){
	return this->formatos[rand()%this->formatos.size()];
}

char Formato::get_nome(std::vector<std::vector<bool>> vect){
	for(int i = 0; i < this->formatos.size(); i++)
		if(this->formatos[i] == vect)
			return this->names[i];
	return '0';

}

std::vector<std::vector<bool>> Formato::get_formato(char nome){
	for(int i = 0; i < this->formatos.size(); i++)
		if(this->names[i] == nome)
			return this->formatos[i];
	return this->formatos[0];
}

std::vector<std::vector<bool>> Formato::get_I(){
	return this->formatos[0];
}

std::vector<std::vector<bool>> Formato::get_J(){
	return this->formatos[1];
}

std::vector<std::vector<bool>> Formato::get_L(){
	return this->formatos[2];
}

std::vector<std::vector<bool>> Formato::get_O(){
	return this->formatos[3];
}

std::vector<std::vector<bool>> Formato::get_S(){
	return this->formatos[4];
}

std::vector<std::vector<bool>> Formato::get_T(){
	return this->formatos[5];
}

std::vector<std::vector<bool>> Formato::get_Z(){
	return this->formatos[6];
}



