#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <windows.h>

unsigned counter = 0;
struct Option
{
	Option(const std::string&, const double);
	double val = 0;
	std::string text;
};
Option::Option(const std::string& txt, const double val) : text(txt), val(val)
{
}
class Question
{
public:
	Question(const std::string&);
	void AddOption(const std::string&, const double);
	void AskQuestion();
	int AnswerQuestion();
private:
	std::string m_Question;
	std::vector<Option>m_Answers;
	double m_Score = 0;
};
void Question::AddOption(const std::string& rhs, const double val)
{
	Option opt(rhs, val);
	m_Answers.push_back(opt);
}
Question::Question(const::std::string& task) : m_Question(task)
{
}
int Randomize(const int i)
{
	return std::rand() % i;
}
void Question::AskQuestion()
{
	std::cout << m_Question << "\n\n";
	std::srand(unsigned(std::time(0)));
	for (unsigned i = 0; i < m_Answers.size(); ++i)
	{
		std::swap(m_Answers[Randomize(m_Answers.size())], m_Answers[Randomize(m_Answers.size())]);
	}
	for (unsigned i = 0; i < m_Answers.size(); ++i)
	{
		char ind = i + 65;
		std::cout << ind << ' ' << m_Answers[i].text << '\n';
	}
}

int Question::AnswerQuestion()
{
	char tmp = 'v';
	unsigned tmpToInt;
	std::cin >> tmp;
	tmpToInt = tmp;
	do
	{
		if (tmpToInt < 97)
		{
			tmpToInt -= 65;
		}
		else
		{
			tmpToInt -= 97;
		}
		m_Score += m_Answers[tmpToInt].val;
		std::cin >> tmp;
		tmpToInt = tmp;
	} while (tmp != 's' && tmp != 'S');

	std::cout << "��������: " << m_Score << "\n����� �������(�): ";
	for (unsigned i = 0; i < m_Answers.size(); ++i)
	{
		if (m_Answers[i].val > 0)
		{
			std::cout << char(i + 65) << ' ';
		}
	}
	std::cout << "\n������ ����� ������: ";
	if (m_Score > 0)
	{
		counter++;
	}
	return m_Score;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(866);

	std::cout << "���� 2 �� ����. �������� �� Mapmo, Dakata, Ikbal � �.\nEdited from 6lokavica to kirilica by: Gazepov\n";
	std::cout << "�� �� ���������� �� ����� ������ �������� �������(�������) � ������ ��� ������ �������� 's'\n";
	std::cout << "��������� �� ��� ������ std::cin\n��� ������� �������� ��� �������� ����� ��������� r\n��� ������� ���������, ����� �������� �� �� ��������, ��������� ���������� �����\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q1("����� � ����� �� ������������ �� CMOVZ?");
	q1.AddOption("���������� �� ��������� �������", 1);
	q1.AddOption("���������� �� �����", -1);
	q1.AddOption("��������� �� ��������� ������", -1);
	q1.AddOption("��������������� �� ������ � ���������", -1);
	exam.push_back(q1);

	Question q2("��� �� ���������� ����������� �� ����� �� ����?");
	q2.AddOption("USB, CAN, I2C", 1);
	q2.AddOption("LPT, PWM, I2C", -1);
	q2.AddOption("Com-port, PCA, PWM", -1);
	q2.AddOption("PCA, ISA, RJ11", -1);
	exam.push_back(q2);

	Question q3("��� �� ���������� ���������� ����������� ������ � �������� ����?");
	q3.AddOption("USB", -1);
	q3.AddOption("LPT", -1);
	q3.AddOption("Com-port", -1);
	q3.AddOption("PCI", 0.5);
	q3.AddOption("ISA", 0.5);
	q3.AddOption("Ethernet", -1);
	exam.push_back(q3);

	Question q4("��� �� ���������� ���������� ����������� ������ � ������ ����?");
	q4.AddOption("USB", 0.25);
	q4.AddOption("LPT", 0.25);
	q4.AddOption("Com-port", 0.25);
	q4.AddOption("PCI", -1);
	q4.AddOption("ISA", -1);
	q4.AddOption("Ethernet", 0.25);
	exam.push_back(q4);

	Question q5("��� �� ������� ��� ������� REQ � GNT?");
	q5.AddOption("�������� �� GNT, � ���� ���� REQ", -5);
	q5.AddOption("�������� �� REQ, ���� ����� GNT", 1);
	q5.AddOption("���� ���������� �� REQ, ������� �� �������� GNT", -1);
	q5.AddOption("���� ���������� �� GNT, ������� �� �������� REQ", -5);
	exam.push_back(q5);

	Question q6("����� �3 � �4 ��� ���������� ��������� �� ����� �� ������ �� ������� ���� �� ����������?\nIMG not found");
	q6.AddOption("Master", -1);
	q6.AddOption("Slave", 1);
	exam.push_back(q6);
	
	Question q7("����� �3 � �4 ��� ���������� ��������� �� ����� �� ������ �� ������� ���� �� ����������?\nIMG not found");
	q7.AddOption("Master", 1);
	q7.AddOption("Slave", -1);
	exam.push_back(q7);

	Question q8("���� ��� �� ���� ������� ��� ����� ������?");
	q8.AddOption("������ �� ������������� ������", -1);
	q8.AddOption("������ �� ����� ���������� �����", -1);
	q8.AddOption("�� ��������� �� ��-������ ��������", -1);
	q8.AddOption("������ �� �����", 1);
	exam.push_back(q8);

	Question q9("����� �������� CRC?");
	q9.AddOption("Cyclic Redundancy Check", 1);
	q9.AddOption("Complete Register Content", -1);
	q9.AddOption("Connection Regulating Chip", -1);
	q9.AddOption("Create Read Clear", -1);
	exam.push_back(q9);

	Question q10("��� ���� ��� ������ �� uC HOST ��� Ethernet?\nImg not found");
	q10.AddOption("TXD", 1);
	q10.AddOption("RXD", -1);
	exam.push_back(q10);

	Question q11("��� ���� ��� ������ �� Ethernet ��� ucHost?\nImg not found");
	q11.AddOption("TXD", -1);
	q11.AddOption("RXD", 1);
	exam.push_back(q11);

	Question q12("����� � DMA?");
	q12.AddOption("Direct Memory Access", 1);
	q12.AddOption("Digital Machine Accumulator", -1);
	q12.AddOption("Digital Memory Access", -1);
	q12.AddOption("Detector of Masked Attacks", -1);
	exam.push_back(q12);

	Question q13("����� �������� � USB3 ������?");
	q13.AddOption("9", 1);
	q13.AddOption("3", -1);
	q13.AddOption("6", -1);
	q13.AddOption("1", -1);
	exam.push_back(q13);

	Question q14("����� �������� � USB2 ������?");
	q14.AddOption("4", 1);
	q14.AddOption("2", -1);
	q14.AddOption("8", -1);
	q14.AddOption("1", -1);
	exam.push_back(q14);

	Question q15("���� D+ � D- sa �������?");
	q15.AddOption("�� ���������� �� ���������", -1);
	q15.AddOption("�� ��-������ ��������", -1);
	q15.AddOption("�� ��-����� ��������� �� ������", -1);
	q15.AddOption("�� ���������������", 1);
	exam.push_back(q15);

	Question q16("����� � SOF?");
	q16.AddOption("Start of Frame", 1);
	q16.AddOption("Superior orbital fissure", -100);
	q16.AddOption("Sequence of Files", -1);
	q16.AddOption("Single Offset Flag", -1);
	exam.push_back(q16);

	Question q17("��� ����� � �� ������?");
	q17.AddOption("�����", 1);
	q17.AddOption("�����", -1);
	q17.AddOption("�����", -1);
	q17.AddOption("��������", -1);
	exam.push_back(q17);

	Question q18("��� ����� � �� ������?");
	q18.AddOption("�����", -1);
	q18.AddOption("�����", -1);
	q18.AddOption("�����", 1);
	q18.AddOption("��������", -1);
	exam.push_back(q18);

	Question q19("�� ����� ������ �����������?");
	q19.AddOption("�� ��������� �� ������������ �������������", 1);
	q19.AddOption("�� ��-����� ������ � �������", -1);
	q19.AddOption("�� ������ �� �����", -1);
	q19.AddOption("�� ���������� �� �������� ����� ������ � ���������", -1);
	exam.push_back(q19);

	Question q20("����� � ���������������� �� predicate?");
	q20.AddOption("�� ����� ����� ������", 1);
	q20.AddOption("�� ���������� ��������", -1);
	q20.AddOption("�� ������ ������������", -1);
	q20.AddOption("�� ������ �������� � ���������", -1);
	exam.push_back(q20);

	Question q21("��� ������� �������� � ������� ���� ��� � �����");
	q21.AddOption("Read", 1);
	q21.AddOption("Write", -1);
	q21.AddOption("Idle", -1);
	exam.push_back(q21);

	Question q22("��� ������� �������� � ������� ���� ��� � �� �������");
	q22.AddOption("Read", -1);
	q22.AddOption("Write", -1);
	q22.AddOption("Idle", 1);
	exam.push_back(q22);

	Question q23("��� ������� �������� � ������� ���� ��� � ������");
	q23.AddOption("Read", -1);
	q23.AddOption("Write", 1);
	q23.AddOption("Idle", -1);
	exam.push_back(q23);

	unsigned questionsCount = exam.size();
	for (unsigned i = 0; i < questionsCount; ++i)
		std::swap(exam[Randomize(exam.size())], exam[Randomize(exam.size())]);
	for (unsigned i = 0; i < exam.size(); ++i)
	{
		if (i == questionsCount)
		{
			std::cout << "������ ��� �������� �������\n��������� ����� �����\n";
			std::cin >> useless;
			system("CLS");
		}
		std::cout << 1 + i << '/' << exam.size() << '\n';
		exam[i].AskQuestion();
		if (exam[i].AnswerQuestion() != 1 && !flag)
			exam.push_back(exam[i]);
		std::cin >> useless;
		system("CLS");
	}
	std::cout << "Congratulations for reaching the end!\nYour score is: " << counter << '/' << exam.size();
	std::cin >> useless;
	return 0;
}