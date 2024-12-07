// Snake.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>


class SnakeGame
{
	struct Node {
		int x;
		int y;
		Node* next;
	};
private:
	Node* snake = nullptr;
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	void Head()
	{
		Node* current = head;
	}

	void Tail()
	{
		Node* current = snake;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		tail = current;
	}

	void SnakeAdd(int x, int y)
	{
		if (snake == nullptr)
		{
			snake = new Node{ x, y, nullptr };
			return;
		}
		Tail();
		Node* current = tail;
		current->next = new Node{ x, y, nullptr };

	}

	void RefreshField(char field[10][10], int align)
	{
		system("cls");

		Node* nextPos = snake;
		if (nextPos != nullptr)
		{
			switch (align)
			{
			case 0:
			
				break;
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
			
				break;
			
			}

		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				field[i][j] = '0';
			}
		}
		Node* current = snake;
		if (current != nullptr)
		{
			field[current->x][current->y] = '*';
		
			while (current->next != nullptr)
			{
				field[current->next->x][current->next->y] = '*';
				current = current->next;
			}
		}
		
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				std::cout << field[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
};





int main()
{
	SnakeGame game;
	char field[10][10];
	game.SnakeAdd(5, 5);
	game.SnakeAdd(5, 6);
	game.SnakeAdd(5, 7);
	int align = 0;

	while (true)
	{
		while (!_kbhit())
		{
			game.RefreshField(field,align);
			Sleep(1000);
		}
		switch (_getch())
		{
		case'w':
			align = 0;
			break;
		case's':
			align = 1;
			break;
		case'a':
			align = 2;
			break;
		case'd':
			align = 3;
			break;
		}

		printf("\nKey struck was '%c'\n", _getch());


	}
	
}
