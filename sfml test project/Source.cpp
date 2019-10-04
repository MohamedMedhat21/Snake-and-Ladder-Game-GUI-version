#include <SFML/Graphics.hpp>
#include  <SFML/Audio.hpp>
#include <iostream>
#include<string>
#include<vector>
#define num_of_items 2
#define num_of_levels 2
#define num_of_players 3
#define num_of_shapes 2
#define num_of_difficulty 2
using namespace std;
using namespace sf;
int dice_res, playerR = 9, playerC = -1, player2R = 9, player2C = -1, score = 0;
int player3R = 9, player3C = -1, player4R = 9, player4C = -1;
bool pressed = false;
bool played1 = true;
bool played2 = false;
bool played3 = false, played4 = false;
bool game_over = false;
int grid[10][10] =
{

	{100,99,98,97,96,95,94,93,92,91},
	{81,82,83,84,85,86,87,88,89,90},
	{80,79,78,77,76,75,74,73,72,71},
	{61,62,63,64,65,66,67,68,69,70},
	{60,59,58,57,56,55,54,53,52,51},
	{41,42,43,44,45,46,47,48,49,50},
	{40,39,38,37,36,35,34,33,32,31},
	{21,22,23,24,25,26,27,28,29,30},
	{20,19,18,17,16,15,14,13,12,11},
	{1, 2, 3, 4, 5, 6, 7, 8, 9,10}
};

int dice_roll()
{
	srand(time(NULL));
	int num = 1 + rand() % 6;

	return num;
}

bool isfound, found = true;
bool open = true;
sf::Music music;
int x, y;
sf::SoundBuffer buffer;
sf::RenderWindow window7(sf::VideoMode(1250, 900), "snake and ladder", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);//hna kda bdy eltitle leha we asmha we adeha el7agt elly mmkn y3mlha elplayer mn y2fl aw ykbr aw kda 
int startmenu()
{
	sf::Sprite background, soundbuttuon, off, playbutton1, aboutbutton;
	playbutton1.setPosition(sf::Vector2f(-290, 155));//////////
	aboutbutton.setPosition(sf::Vector2f(480, 695));
	off.setPosition(sf::Vector2f(50, 0));
	sf::Texture texture, texture1, texture2, texture3, texture4;
	texture.setSmooth(true);
	texture.loadFromFile("background.png");
	background.setTexture(texture);
	background.setTextureRect(sf::IntRect(0, 0, 1856, 1101));
	background.setScale(0.7, 0.9);
	texture3.loadFromFile("playbutton.png");
	playbutton1.setTexture(texture3);
	texture1.loadFromFile("sound button.png");
	soundbuttuon.setTexture(texture1);
	soundbuttuon.setScale(0.5, 0.5);
	texture4.loadFromFile("about button.png");
	aboutbutton.setScale(0.8, 0.8);
	aboutbutton.setTexture(texture4);
	texture2.loadFromFile("off.png");
	off.setTexture(texture2);
	off.setScale(0.5, 0.5);
	music.openFromFile("sound/POL-mad-run-short.ogg");
	music.setVolume(50);
	//music.setPitch(2); BYSR3 ELSOT
	music.setLoop(true); //btfdl sh8alaaaaaaaa tol el3ba 
	music.play();
	//sf::Sound::Status Status = music.getStatus();
	int Selected_Item_indx = 0; //hymshy be el index of array ;;;
	Text text[num_of_items]; //array gwaa 3 amakn ll play about  we exist 
	Font font;
	font.loadFromFile("font3.ttf");
	text[0].setFont(font);
	text[0].setFillColor(Color::White);
	text[0].setString("Play");
	text[0].setPosition(Vector2f(600, 600));
	text[0].setCharacterSize(70);

	text[1].setFont(font);
	text[1].setFillColor(Color::White);
	text[1].setString("About");
	text[1].setPosition(Vector2f(600, 700));
	text[1].setCharacterSize(70);

	while (window7.isOpen())
	{
		sf::Event event;
		while (window7.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window7.close();
				break;
			case sf::Event::MouseMoved:
				x = event.mouseMove.x, y = event.mouseMove.y;
				break;
			case sf::Event::MouseButtonPressed:
				if (x >= 0 && x <= 27 && y >= 0 && y <= 43) {
					switch (event.key.code) {
					case sf::Mouse::Left:
						music.play();
						open = true;
						break;
					}
				}
				if (x >= 57 && x <= 95 && y >= 0 && y <= 33) {
					switch (event.key.code) {
					case sf::Mouse::Left:
						open = false;
						music.stop();
						break;
					}
				}
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					if (Selected_Item_indx - 1 >= 0) {
						text[Selected_Item_indx].setFillColor(Color::White);
						Selected_Item_indx--;
						text[Selected_Item_indx].setFillColor(Color::Red);
					}
					break;

				case sf::Keyboard::Down:
					if (Selected_Item_indx + 1 < num_of_items) {
						text[Selected_Item_indx].setFillColor(Color::White);
						Selected_Item_indx++;
						text[Selected_Item_indx % num_of_items].setFillColor(Color::Red);
					}
					break;
				case ::Keyboard::Enter:
					return Selected_Item_indx;
					break;
				}
			}
		}
		window7.clear();
		window7.draw(background);
		window7.draw(soundbuttuon);
		window7.draw(off);
		window7.draw(playbutton1);
		window7.draw(aboutbutton);
		for (int i = 0; i < num_of_items; i++)
		{
			window7.draw(text[i]);
		}
		window7.display();
	}
}
int start_level() {
	int Selected_level_indx = 0;
	Text levelss[num_of_levels];
	Font font2;
	font2.loadFromFile("font3.ttf");
	levelss[0].setFont(font2);
	levelss[0].setFillColor(Color::White);
	levelss[0].setString("level (1)");
	levelss[0].setPosition(Vector2f(430, 350));
	levelss[0].setCharacterSize(130);

	levelss[1].setFont(font2);
	levelss[1].setFillColor(Color::White);
	levelss[1].setString("level (2)");
	levelss[1].setPosition(Vector2f(430, 500));
	levelss[1].setCharacterSize(130);


	if (open == true) {
		music.play();
	}
	//music.setPitch(2); BYSR3 ELSOT
	//music.setLoop(true); //btfdl sh8alaaaaaaaa tol el3ba 

	while (window7.isOpen())
	{
		sf::Event event;
		while (window7.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window7.close();
				break;
			case ::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::M:
					music.stop();
					open = false;
					break;
				case::Keyboard::O:
					music.play();
					open = true;
					break;

				case sf::Keyboard::Up:
					if (Selected_level_indx - 1 >= 0) {
						levelss[Selected_level_indx].setFillColor(Color::White);
						Selected_level_indx--;
						levelss[Selected_level_indx].setFillColor(Color::Red);
					}
					break;

				case sf::Keyboard::Down:
					if (Selected_level_indx + 1 < num_of_levels) {
						levelss[Selected_level_indx].setFillColor(Color::White);
						Selected_level_indx++;
						levelss[Selected_level_indx % num_of_levels].setFillColor(Color::Red);
					}
					break;
				case ::Keyboard::Enter:
					return Selected_level_indx;
					break;
				}
			}
			Sprite levelsbackground;
			Texture levels;
			levels.setSmooth(true);
			levels.loadFromFile("levelbackground.png");
			levelsbackground.setScale(1.5, 1.3);
			levelsbackground.setTexture(levels);

			Text Levels;
			Levels.setFont(font2);
			Levels.setString("Levels");
			Levels.setFillColor(Color::Yellow);
			Levels.setCharacterSize(200);
			Levels.setPosition(Vector2f(360, 80));


			window7.clear();
			window7.draw(levelsbackground);
			window7.draw(Levels);
			for (int i = 0; i < num_of_levels; i++)
			{
				window7.draw(levelss[i]);
			}
			window7.display();

		}
	}
}
void level1_2playerss() {
	int dice_res, playerR = 9, playerC = -1, player2R = 9, player2C = -1, score = 0;
	int player3R = 9, player3C = -1, player4R = 9, player4C = -1;
	bool pressed = false;
	bool played1 = true;
	bool played2 = false;
	bool played3 = false, played4 = false;
	bool game_over = false;
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "SnakePhobia");
	window.setKeyRepeatEnabled(false);
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture dice_1;
	sf::Texture dice_2;
	sf::Texture dice_3;
	sf::Texture dice_4;
	sf::Texture dice_5;
	sf::Texture dice_6;
	sf::Texture playeeer;
	sf::Texture playeeer1;
	sf::Texture congratulations;
	if (!texture.loadFromFile("numbered board.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer.loadFromFile("bird.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer1.loadFromFile("g.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture2.loadFromFile("LADDER_SPRITE.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture3.loadFromFile("57459272_638862999870607_5341563182932557824_n.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture4.loadFromFile("perspective-dice-six-faces-random.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_1.loadFromFile("dice-six-faces-one.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_2.loadFromFile("dice-six-faces-two.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_3.loadFromFile("dice-six-faces-three.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_4.loadFromFile("dice-six-faces-four.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_5.loadFromFile("dice-six-faces-five.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_6.loadFromFile("dice-six-faces-six.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!congratulations.loadFromFile("Congratulations.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	//shapes
	sf::RectangleShape square10(sf::Vector2f(60.f, 80.f));	//endofshapes
	sf::RectangleShape square20(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square30(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square40(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square50(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square60(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square70(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square80(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square90(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square100(sf::Vector2f(80.f, 80.f));

	square10.setFillColor(sf::Color(255, 255, 255, 0));
	square20.setFillColor(sf::Color(255, 255, 255, 0));
	square30.setFillColor(sf::Color(255, 255, 255, 0));
	square40.setFillColor(sf::Color(255, 255, 255, 0));
	square50.setFillColor(sf::Color(255, 255, 255, 0));
	square60.setFillColor(sf::Color(255, 255, 255, 0));
	square70.setFillColor(sf::Color(255, 255, 255, 0));
	square80.setFillColor(sf::Color(255, 255, 255, 0));
	square90.setFillColor(sf::Color(255, 255, 255, 0));
	square100.setFillColor(sf::Color(255, 255, 255, 0));
	//Declaration
	sf::Sprite dice;
	sf::Sprite dice1;
	sf::Sprite dice2;
	sf::Sprite dice3;
	sf::Sprite dice4;
	sf::Sprite dice5;
	sf::Sprite dice6;

	sf::Sprite sprite;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
	sf::Sprite sprite5;
	sf::Sprite sprite6;
	sf::Sprite sprite7;
	sf::Sprite sprite8;
	sf::Sprite sprite9;
	sf::Sprite sprite10;
	sf::Sprite playeer1;
	sf::Sprite computer1;
	sf::Sprite playeer2;
	sf::Sprite playeer3;
	sf::Sprite playeer4;
	sf::Sprite congrats;
	//end of declaration
	//textures
	//ladders
	sprite.setTexture(texture);
	sprite1.setTexture(texture2);
	sprite2.setTexture(texture2);
	sprite3.setTexture(texture2);
	sprite4.setTexture(texture2);
	sprite5.setTexture(texture2);
	//snakes
	sprite6.setTexture(texture3);
	sprite7.setTexture(texture3);
	sprite8.setTexture(texture3);
	sprite9.setTexture(texture3);
	sprite10.setTexture(texture3);
	playeer1.setTexture(playeeer);
	playeer2.setTexture(playeeer1);
	playeer3.setTexture(playeeer);
	playeer4.setTexture(playeeer);
	computer1.setTexture(playeeer);
	congrats.setTexture(congratulations);
	//dice
	dice.setTexture(texture4);
	dice1.setTexture(dice_1);
	dice2.setTexture(dice_2);
	dice3.setTexture(dice_3);
	dice4.setTexture(dice_4);
	dice5.setTexture(dice_5);
	dice6.setTexture(dice_6);
	//dice position
	dice1.setPosition(sf::Vector2f(-700, -700));
	dice2.setPosition(sf::Vector2f(-700, -700));
	dice3.setPosition(sf::Vector2f(-700, -700));
	dice4.setPosition(sf::Vector2f(-700, -700));
	dice5.setPosition(sf::Vector2f(-700, -700));
	dice6.setPosition(sf::Vector2f(-700, -700));

	//end of dice
	//end of setting textures
	//rotation
	sprite1.rotate(35.f);
	sprite2.rotate(135.f);
	sprite3.rotate(60.f);
	sprite4.rotate(30.f);
	sprite5.rotate(5.f);
	sprite6.rotate(25.f);
	sprite7.rotate(25.f);
	sprite8.rotate(-20.f);
	sprite9.rotate(-35.f);
	sprite10.rotate(70.f);
	//square10.rotate(45.f);
	//end of rotation
	//scale
	sprite.setScale(sf::Vector2f(0.833, 0.83));
	sprite1.setScale(sf::Vector2f(0.2, 0.2));
	sprite2.setScale(sf::Vector2f(0.2, 0.2));
	sprite3.setScale(sf::Vector2f(0.2, 0.2));
	sprite4.setScale(sf::Vector2f(0.2, 0.2));
	sprite5.setScale(sf::Vector2f(0.2, 0.2));
	sprite6.setScale(sf::Vector2f(1.6, 1.6));
	sprite7.setScale(sf::Vector2f(1.2, 1.2));
	sprite8.setScale(sf::Vector2f(1.5, 1.5));
	sprite9.setScale(sf::Vector2f(1.7, 1.7));
	sprite10.setScale(sf::Vector2f(1.4, 1.4));
	playeer1.setScale(sf::Vector2f(0.5, 0.5));///////////////////

	playeer2.setScale(sf::Vector2f(0.5, 0.5));
	playeer3.setScale(sf::Vector2f(0.16, 0.16));
	playeer4.setScale(sf::Vector2f(0.16, 0.16));
	computer1.setScale(sf::Vector2f(0.16, 0.16));
	square10.setScale(sf::Vector2f(1.5, 1.5));
	congrats.setScale(0.3, 0.3);
	//end of scale
	//position
	sprite1.setPosition(sf::Vector2f(900, 690));
	sprite2.setPosition(sf::Vector2f(600, 350));
	sprite3.setPosition(sf::Vector2f(600, 599));
	sprite4.setPosition(sf::Vector2f(155, 500));
	sprite5.setPosition(sf::Vector2f(940, 40));
	sprite6.setPosition(sf::Vector2f(200, 27));
	sprite7.setPosition(sf::Vector2f(800, 450));
	sprite8.setPosition(sf::Vector2f(600, 75));
	sprite9.setPosition(sf::Vector2f(220, 360));
	sprite10.setPosition(sf::Vector2f(530, 820));
	playeer1.setPosition(sf::Vector2f(-120, 900));
	playeer2.setPosition(sf::Vector2f(-120, 900));
	playeer3.setPosition(sf::Vector2f(-120, 900));
	playeer4.setPosition(sf::Vector2f(-120, 900));
	computer1.setPosition(sf::Vector2f(-120, 900));
	//player1.setSmooth
	//end of position

	//squares
	square10.setPosition(sf::Vector2f(700, 910));
	square20.setPosition(sf::Vector2f(10, 705));
	square30.setPosition(sf::Vector2f(310, 710));
	square40.setPosition(sf::Vector2f(810, 410));
	square50.setPosition(sf::Vector2f(215, 310));
	square60.setPosition(sf::Vector2f(510, 310));
	square70.setPosition(sf::Vector2f(910, 310));
	square80.setPosition(sf::Vector2f(210, 10));
	square90.setPosition(sf::Vector2f(610, 10));
	square100.setPosition(sf::Vector2f(510, 810));
	congrats.setPosition(-1100, -1100);


	int cnt = 2;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played1 == true && game_over == false)
		{
			if (grid[playerR][playerC] + dice_res <= 100)
			{

				if (playerC - dice_res < 0 && playerR % 2 == 0)
				{
					dice_res -= (playerC);
					playerC = 0;
					playerR--;
					dice_res--;
				}
				if (playerC + dice_res > 9 && playerR % 2 != 0 || playerC - dice_res > 9 && playerR % 2 == 0)
				{
					dice_res -= (9 - playerC);
					playerC += (9 - playerC);
					playerR--;
					dice_res--;
				}


				if (playerR % 2 != 0)
				{
					playerC += dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition(playerC * 100, playerR * 100);
					pressed = false;
				}
				else
				{
					playerC -= dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition((playerC * 100), playerR * 100);
					pressed = false;
				}
				cout << "R= " << playerR << endl;
				cout << "C= " << playerC << endl;





				switch (grid[playerR][playerC]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 94:
					playerR = 3;
					playerC = 7;

					break;


				case 98:
					playerR = 3;
					playerC = 1;

					break;


				case 63:
					playerR = 5;
					playerC = 4;

					break;


				case 52:
					playerR = 6;
					playerC = 7;

					break;


				case 15:
					playerR = 9;
					playerC = 2;

					break;


				case 70:
					playerR = 0;
					playerC = 9;

					break;


				case 66:
					playerR = 1;
					playerC = 3;

					break;


				case 21:
					playerR = 5;
					playerC = 1;

					break;


				case 24:
					playerR = 6;
					playerC = 6;

					break;


				case 8:
					playerR = 7;
					playerC = 9;

					break;


				default:
					break;
				}




				if (grid[playerR][playerC] == 100)
				{
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played1 = false;
			played2 = true;
		} ///end of player 1



		///player 2
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played2 == true && game_over == false)
		{
			if (grid[player2R][player2C] + dice_res <= 100)
			{

				if (player2C - dice_res < 0 && player2R % 2 == 0)
				{
					dice_res -= (player2C);
					player2C = 0;
					player2R--;
					dice_res--;
				}
				if (player2C + dice_res > 9 && player2R % 2 != 0 || player2C - dice_res > 9 && player2R % 2 == 0)
				{
					dice_res -= (9 - player2C);
					player2C += (9 - player2C);
					player2R--;
					dice_res--;
				}


				if (player2R % 2 != 0)
				{
					player2C += dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition(player2C * 100, player2R * 100);
					pressed = false;
				}
				else
				{
					player2C -= dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition((player2C * 100), player2R * 100);
					pressed = false;
				}
				cout << "R2= " << player2R << endl;
				cout << "C2= " << player2C << endl;





				switch (grid[player2R][player2C]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 94:
					player2R = 3;
					player2C = 7;

					break;


				case 98:
					player2R = 3;
					player2C = 1;

					break;


				case 63:
					player2R = 5;
					player2C = 4;

					break;


				case 52:
					player2R = 6;
					player2C = 7;

					break;


				case 15:
					player2R = 9;
					player2C = 2;

					break;


				case 70:
					player2R = 0;
					player2C = 9;

					break;


				case 66:
					player2R = 1;
					player2C = 3;

					break;


				case 21:
					player2R = 5;
					player2C = 1;

					break;


				case 24:
					player2R = 6;
					player2C = 6;

					break;


				case 8:
					player2R = 7;
					player2C = 9;

					break;


				default:
					break;
				}



				if (grid[player2R][player2C] == 100)
				{
					///congratulations
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played1 = true;
			played2 = false;
		}
		cnt++;
		playeer1.setPosition(playerC * 100, playerR * 100);
		playeer2.setPosition(player2C * 100, player2R * 100);

		window.clear();

		window.draw(sprite);
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);
		window.draw(sprite8);
		window.draw(sprite9);
		window.draw(sprite10);
		window.draw(square10);
		window.draw(playeer1);
		window.draw(playeer2);
		window.draw(computer1);
		window.draw(square20);
		window.draw(square30);
		window.draw(square40);
		window.draw(square50);
		window.draw(square60);
		window.draw(square70);
		window.draw(square80);
		window.draw(square90);
		window.draw(square100);

		window.draw(dice1);
		window.draw(dice2);
		window.draw(dice3);
		window.draw(dice4);
		window.draw(dice5);
		window.draw(dice6);
		window.draw(congrats);
		window.display();
	}
}
void level1_3players() {
	int dice_res, playerR = 9, playerC = -1, player2R = 9, player2C = -1, score = 0;
	int player3R = 9, player3C = -1, player4R = 9, player4C = -1;
	bool pressed = false;
	bool played1 = true;
	bool played2 = false;
	bool played3 = false, played4 = false;
	bool game_over = false;
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "SnakePhobia");
	window.setKeyRepeatEnabled(false);

	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture dice_1;
	sf::Texture dice_2;
	sf::Texture dice_3;
	sf::Texture dice_4;
	sf::Texture dice_5;
	sf::Texture dice_6;
	sf::Texture playeeer;
	sf::Texture playeeer1;
	sf::Texture playeeer2;
	sf::Texture congratulations;
	sf::Texture bomber;
	sf::Texture rockets;

	if (!texture.loadFromFile("numbered board.png"))
	{
		std::cout << "loading error" << std::endl;
	}


	if (!rockets.loadFromFile("bomb_PNG32.png"))
	{
		std::cout << "loading error" << std::endl;

	}

	if (!bomber.loadFromFile("Rocket-PNG-File.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer.loadFromFile("q.png"))///////
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer2.loadFromFile("k.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer1.loadFromFile("w.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture2.loadFromFile("LADDER_SPRITE.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture3.loadFromFile("57459272_638862999870607_5341563182932557824_n.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture4.loadFromFile("perspective-dice-six-faces-random.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_1.loadFromFile("dice-six-faces-one.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_2.loadFromFile("dice-six-faces-two.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_3.loadFromFile("dice-six-faces-three.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_4.loadFromFile("dice-six-faces-four.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_5.loadFromFile("dice-six-faces-five.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_6.loadFromFile("dice-six-faces-six.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!congratulations.loadFromFile("Congratulations.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	//shapes
	sf::RectangleShape square10(sf::Vector2f(60.f, 80.f));	//endofshapes
	sf::RectangleShape square20(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square30(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square40(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square50(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square60(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square70(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square80(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square90(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square100(sf::Vector2f(80.f, 80.f));

	square10.setFillColor(sf::Color(255, 255, 255, 0));
	square20.setFillColor(sf::Color(255, 255, 255, 0));
	square30.setFillColor(sf::Color(255, 255, 255, 0));
	square40.setFillColor(sf::Color(255, 255, 255, 0));
	square50.setFillColor(sf::Color(255, 255, 255, 0));
	square60.setFillColor(sf::Color(255, 255, 255, 0));
	square70.setFillColor(sf::Color(255, 255, 255, 0));
	square80.setFillColor(sf::Color(255, 255, 255, 0));
	square90.setFillColor(sf::Color(255, 255, 255, 0));
	square100.setFillColor(sf::Color(255, 255, 255, 0));
	//Declaration
	sf::Sprite dice;
	sf::Sprite dice1;
	sf::Sprite dice2;
	sf::Sprite dice3;
	sf::Sprite dice4;
	sf::Sprite dice5;
	sf::Sprite dice6;
	//bombs
	sf::Sprite bomb1;
	sf::Sprite bomb2;
	sf::Sprite bomb3;
	sf::Sprite bomb4;
	sf::Sprite bomb5;
	sf::Sprite bomb6;
	//end of bombs
	//rockets
	sf::Sprite rocket1;
	sf::Sprite rocket2;
	sf::Sprite rocket3;
	sf::Sprite rocket4;
	sf::Sprite rocket5;

	//end of rockets
	bomb1.setTexture(bomber);
	bomb2.setTexture(bomber);
	bomb3.setTexture(bomber);
	bomb4.setTexture(bomber);
	bomb5.setTexture(bomber);
	bomb6.setTexture(bomber);
	//
	rocket1.setTexture(rockets);
	rocket2.setTexture(rockets);
	rocket3.setTexture(rockets);
	rocket4.setTexture(rockets);
	rocket5.setTexture(rockets);

	//
	rocket1.setPosition(sf::Vector2f(810, 290));
	rocket2.setPosition(sf::Vector2f(510, 90));
	rocket3.setPosition(sf::Vector2f(610, 490));
	rocket4.setPosition(sf::Vector2f(210, 690));
	rocket5.setPosition(sf::Vector2f(10, 390));

	rocket1.setScale(sf::Vector2f(0.2, 0.2));
	rocket2.setScale(sf::Vector2f(0.2, 0.2));
	rocket3.setScale(sf::Vector2f(0.2, 0.2));
	rocket4.setScale(sf::Vector2f(0.2, 0.2));
	rocket5.setScale(sf::Vector2f(0.2, 0.2));

	bomb1.setScale(sf::Vector2f(0.2, 0.2));
	bomb2.setScale(sf::Vector2f(0.2, 0.2));
	bomb3.setScale(sf::Vector2f(0.2, 0.2));
	bomb4.setScale(sf::Vector2f(0.2, 0.2));
	bomb6.setScale(sf::Vector2f(0.2, 0.2));
	bomb5.setScale(sf::Vector2f(0.2, 0.2));

	//
	bomb1.setPosition(sf::Vector2f(210, 690));
	bomb2.setPosition(sf::Vector2f(510, 90));
	bomb3.setPosition(sf::Vector2f(810, 290));
	bomb4.setPosition(sf::Vector2f(610, 790));
	bomb5.setPosition(sf::Vector2f(110, 890));
	bomb6.setPosition(sf::Vector2f(10, 290));

	sf::Sprite sprite;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
	sf::Sprite sprite5;
	sf::Sprite sprite6;
	sf::Sprite sprite7;
	sf::Sprite sprite8;
	sf::Sprite sprite9;
	sf::Sprite sprite10;
	sf::Sprite playeer1;
	sf::Sprite computer1;
	sf::Sprite playeer2;
	sf::Sprite playeer3;
	sf::Sprite playeer4;
	sf::Sprite congrats;
	//end of declaration
	//textures
	//ladders
	sprite.setTexture(texture);
	sprite1.setTexture(texture2);
	sprite2.setTexture(texture2);
	sprite3.setTexture(texture2);
	sprite4.setTexture(texture2);
	sprite5.setTexture(texture2);
	//snakes


	sprite6.setTexture(texture3);
	sprite7.setTexture(texture3);
	sprite8.setTexture(texture3);
	sprite9.setTexture(texture3);
	sprite10.setTexture(texture3);
	playeer1.setTexture(playeeer);
	playeer2.setTexture(playeeer1);
	playeer3.setTexture(playeeer2);
	playeer4.setTexture(playeeer);
	computer1.setTexture(playeeer);
	congrats.setTexture(congratulations);
	//dice
	dice.setTexture(texture4);
	dice1.setTexture(dice_1);
	dice2.setTexture(dice_2);
	dice3.setTexture(dice_3);
	dice4.setTexture(dice_4);
	dice5.setTexture(dice_5);
	dice6.setTexture(dice_6);
	//dice position
	dice1.setPosition(sf::Vector2f(-700, -700));
	dice2.setPosition(sf::Vector2f(-700, -700));
	dice3.setPosition(sf::Vector2f(-700, -700));
	dice4.setPosition(sf::Vector2f(-700, -700));
	dice5.setPosition(sf::Vector2f(-700, -700));
	dice6.setPosition(sf::Vector2f(-700, -700));

	//end of dice
	//end of setting textures
	//rotation
	sprite1.rotate(35.f);
	sprite2.rotate(135.f);
	sprite3.rotate(60.f);
	sprite4.rotate(30.f);
	sprite5.rotate(5.f);
	sprite6.rotate(25.f);
	sprite7.rotate(25.f);
	sprite8.rotate(-20.f);
	sprite9.rotate(-35.f);
	sprite10.rotate(70.f);
	//square10.rotate(45.f);
	//end of rotation
	//scale
	sprite.setScale(sf::Vector2f(0.833, 0.83));
	sprite1.setScale(sf::Vector2f(0.2, 0.2));
	sprite2.setScale(sf::Vector2f(0.2, 0.2));
	sprite3.setScale(sf::Vector2f(0.2, 0.2));
	sprite4.setScale(sf::Vector2f(0.2, 0.2));
	sprite5.setScale(sf::Vector2f(0.2, 0.2));
	sprite6.setScale(sf::Vector2f(1.6, 1.6));
	sprite7.setScale(sf::Vector2f(1.2, 1.2));
	sprite8.setScale(sf::Vector2f(1.5, 1.5));
	sprite9.setScale(sf::Vector2f(1.7, 1.7));
	sprite10.setScale(sf::Vector2f(1.4, 1.4));
	playeer1.setScale(sf::Vector2f(0.5, 0.5));/////////
	playeer2.setScale(sf::Vector2f(0.5, 0.5));/////////
	playeer3.setScale(sf::Vector2f(0.5, 0.5));///////
	playeer4.setScale(sf::Vector2f(0.16, 0.16));
	computer1.setScale(sf::Vector2f(0.16, 0.16));
	square10.setScale(sf::Vector2f(1.5, 1.5));
	congrats.setScale(0.3, 0.3);
	//end of scale
	//position
	sprite1.setPosition(sf::Vector2f(900, 690));
	sprite2.setPosition(sf::Vector2f(600, 350));
	sprite3.setPosition(sf::Vector2f(600, 599));
	sprite4.setPosition(sf::Vector2f(155, 500));
	sprite5.setPosition(sf::Vector2f(940, 40));
	sprite6.setPosition(sf::Vector2f(200, 27));
	sprite7.setPosition(sf::Vector2f(800, 450));
	sprite8.setPosition(sf::Vector2f(600, 75));
	sprite9.setPosition(sf::Vector2f(220, 360));
	sprite10.setPosition(sf::Vector2f(530, 820));
	playeer1.setPosition(sf::Vector2f(-120, 900));
	playeer2.setPosition(sf::Vector2f(-120, 900));
	playeer3.setPosition(sf::Vector2f(-120, 900));
	playeer4.setPosition(sf::Vector2f(-120, 900));
	computer1.setPosition(sf::Vector2f(-120, 900));
	//player1.setSmooth
	//end of position

	//squares
	square10.setPosition(sf::Vector2f(700, 910));
	square20.setPosition(sf::Vector2f(10, 705));
	square30.setPosition(sf::Vector2f(310, 710));
	square40.setPosition(sf::Vector2f(810, 410));
	square50.setPosition(sf::Vector2f(215, 310));
	square60.setPosition(sf::Vector2f(510, 310));
	square70.setPosition(sf::Vector2f(910, 310));
	square80.setPosition(sf::Vector2f(210, 10));
	square90.setPosition(sf::Vector2f(610, 10));
	square100.setPosition(sf::Vector2f(510, 810));
	congrats.setPosition(-1100, -1100);


	int cnt = 2;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played1 == true && game_over == false)
		{
			if (grid[playerR][playerC] + dice_res <= 100)
			{

				if (playerC - dice_res < 0 && playerR % 2 == 0)
				{
					dice_res -= (playerC);
					playerC = 0;
					playerR--;
					dice_res--;
				}
				if (playerC + dice_res > 9 && playerR % 2 != 0 || playerC - dice_res > 9 && playerR % 2 == 0)
				{
					dice_res -= (9 - playerC);
					playerC += (9 - playerC);
					playerR--;
					dice_res--;
				}


				if (playerR % 2 != 0)
				{
					playerC += dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition(playerC * 100, playerR * 100);
					pressed = false;
				}
				else
				{
					playerC -= dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition((playerC * 100), playerR * 100);
					pressed = false;
				}
				cout << "R= " << playerR << endl;
				cout << "C= " << playerC << endl;
				switch (grid[playerR][playerC]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 94:
					playerR = 3;
					playerC = 7;

					break;


				case 98:
					playerR = 3;
					playerC = 1;

					break;


				case 63:
					playerR = 5;
					playerC = 4;

					break;


				case 52:
					playerR = 6;
					playerC = 7;

					break;


				case 15:
					playerR = 9;
					playerC = 2;

					break;


				case 70:
					playerR = 0;
					playerC = 9;

					break;


				case 66:
					playerR = 1;
					playerC = 3;

					break;


				case 21:
					playerR = 5;
					playerC = 1;

					break;


				case 24:
					playerR = 6;
					playerC = 6;

					break;


				case 8:
					playerR = 7;
					playerC = 9;

					break;


				default:
					break;
				}




				if (grid[playerR][playerC] == 100)
				{
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played1 = false;
			played2 = true;
			played3 = false;
		} ///end of player 1



		///player 2
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played2 == true && game_over == false)
		{
			if (grid[player2R][player2C] + dice_res <= 100)
			{

				if (player2C - dice_res < 0 && player2R % 2 == 0)
				{
					dice_res -= (player2C);
					player2C = 0;
					player2R--;
					dice_res--;
				}
				if (player2C + dice_res > 9 && player2R % 2 != 0 || player2C - dice_res > 9 && player2R % 2 == 0)
				{
					dice_res -= (9 - player2C);
					player2C += (9 - player2C);
					player2R--;
					dice_res--;
				}


				if (player2R % 2 != 0)
				{
					player2C += dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition(player2C * 100, player2R * 100);
					pressed = false;
				}
				else
				{
					player2C -= dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition((player2C * 100), player2R * 100);
					pressed = false;
				}
				cout << "R2= " << player2R << endl;
				cout << "C2= " << player2C << endl;
				switch (grid[player2R][player2C]) // it is snakes and ladders, numbers represent the snakes and ladders
				{



				case 94:
					player2R = 3;
					player2C = 7;

					break;


				case 98:
					player2R = 3;
					player2C = 1;

					break;


				case 63:
					player2R = 5;
					player2C = 4;

					break;


				case 52:
					player2R = 6;
					player2C = 7;

					break;


				case 15:
					player2R = 9;
					player2C = 2;

					break;


				case 70:
					player2R = 0;
					player2C = 9;

					break;


				case 66:
					player2R = 1;
					player2C = 3;

					break;


				case 21:
					player2R = 5;
					player2C = 1;

					break;


				case 24:
					player2R = 6;
					player2C = 6;

					break;


				case 8:
					player2R = 7;
					player2C = 9;

					break;


				default:
					break;
				}



				if (grid[player2R][player2C] == 100)
				{
					///congratulations
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played3 = true;
			played2 = false;
			played1 = false;
		}


		//
		///player 3
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played3 == true && game_over == false)
		{
			if (grid[player3R][player3C] + dice_res <= 100)
			{

				if (player3C - dice_res < 0 && player3R % 2 == 0)
				{
					dice_res -= (player3C);
					player3C = 0;
					player3R--;
					dice_res--;
				}
				if (player3C + dice_res > 9 && player3R % 2 != 0 || player3C - dice_res > 9 && player3R % 2 == 0)
				{
					dice_res -= (9 - player3C);
					player3C += (9 - player3C);
					player3R--;
					dice_res--;
				}
				if (player3R % 2 != 0)
				{
					player3C += dice_res;
					score = grid[player3R][player3C] - 1;
					cout << score << endl;
					playeer3.setPosition(player3C * 100, player3R * 100);
					pressed = false;
				}
				else
				{
					player3C -= dice_res;
					score = grid[player3R][player3C] - 1;
					cout << score << endl;
					playeer3.setPosition((player3C * 100), player2R * 100);
					pressed = false;
				}
				cout << "R2= " << player3R << endl;
				cout << "C2= " << player3C << endl;
				switch (grid[player3R][player3C]) // it is snakes and ladders, numbers represent the snakes and ladders
				{



				case 94:
					player3R = 3;
					player3C = 7;

					break;


				case 98:
					player3R = 3;
					player3C = 1;

					break;


				case 63:
					player3R = 5;
					player3C = 4;

					break;


				case 52:
					player3R = 6;
					player3C = 7;

					break;


				case 15:
					player3R = 9;
					player3C = 2;

					break;


				case 70:
					player3R = 0;
					player3C = 9;

					break;


				case 66:
					player3R = 1;
					player3C = 3;

					break;


				case 21:
					player3R = 5;
					player3C = 1;

					break;


				case 24:
					player3R = 6;
					player3C = 6;

					break;
				case 8:
					player3R = 7;
					player3C = 9;

					break;
				default:
					break;
				}
				if (grid[player3R][player3C] == 100)
				{
					///congratulations
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played1 = true;
			played2 = false;
			played3 = false;
		}

		//
		cnt++;
		playeer1.setPosition(playerC * 100, playerR * 100);
		playeer2.setPosition(player2C * 100, player2R * 100);
		playeer3.setPosition(player3C * 100, player3R * 100);
		window.clear();
		window.draw(sprite);
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);
		window.draw(sprite8);
		window.draw(sprite9);
		window.draw(sprite10);
		window.draw(square10);
		window.draw(playeer1);
		window.draw(playeer2);
		window.draw(playeer3);
		window.draw(computer1);
		window.draw(square20);
		window.draw(square30);
		window.draw(square40);
		window.draw(square50);
		window.draw(square60);
		window.draw(square70);
		window.draw(square80);
		window.draw(square90);
		window.draw(square100);

		window.draw(dice1);
		window.draw(dice2);
		window.draw(dice3);
		window.draw(dice4);
		window.draw(dice5);
		window.draw(dice6);
		window.draw(congrats);
		window.display();
	}
}
void level1_4players() {
	int dice_res, playerR = 9, playerC = -1, player2R = 9, player2C = -1, score = 0;
	int player3R = 9, player3C = -1, player4R = 9, player4C = -1;
	bool pressed = false;
	bool played1 = true;
	bool played2 = false;
	bool played3 = false, played4 = false;
	bool game_over = false;
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "SnakePhobia");
	window.setKeyRepeatEnabled(false);
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture dice_1;
	sf::Texture dice_2;
	sf::Texture dice_3;
	sf::Texture dice_4;
	sf::Texture dice_5;
	sf::Texture dice_6;
	sf::Texture playeeer;
	sf::Texture playeeer1;
	sf::Texture playeeer8;
	sf::Texture playeeer9;
	sf::Texture playeeer10;
	sf::Texture congratulations;
	sf::Texture bomber;
	sf::Texture rockets;

	if (!texture.loadFromFile("numbered board.png"))
	{
		std::cout << "loading error" << std::endl;
	}

	if (!rockets.loadFromFile("bomb_PNG32.png"))
	{
		std::cout << "loading error" << std::endl;

	}

	if (!bomber.loadFromFile("Rocket-PNG-File.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer8.loadFromFile("j.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer10.loadFromFile("o.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer1.loadFromFile("a.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer9.loadFromFile("aa.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture2.loadFromFile("LADDER_SPRITE.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture3.loadFromFile("57459272_638862999870607_5341563182932557824_n.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture4.loadFromFile("perspective-dice-six-faces-random.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_1.loadFromFile("dice-six-faces-one.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_2.loadFromFile("dice-six-faces-two.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_3.loadFromFile("dice-six-faces-three.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_4.loadFromFile("dice-six-faces-four.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_5.loadFromFile("dice-six-faces-five.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_6.loadFromFile("dice-six-faces-six.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!congratulations.loadFromFile("Congratulations.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	//shapes
	sf::RectangleShape square10(sf::Vector2f(60.f, 80.f));	//endofshapes
	sf::RectangleShape square20(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square30(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square40(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square50(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square60(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square70(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square80(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square90(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square100(sf::Vector2f(80.f, 80.f));

	square10.setFillColor(sf::Color(255, 255, 255, 0));
	square20.setFillColor(sf::Color(255, 255, 255, 0));
	square30.setFillColor(sf::Color(255, 255, 255, 0));
	square40.setFillColor(sf::Color(255, 255, 255, 0));
	square50.setFillColor(sf::Color(255, 255, 255, 0));
	square60.setFillColor(sf::Color(255, 255, 255, 0));
	square70.setFillColor(sf::Color(255, 255, 255, 0));
	square80.setFillColor(sf::Color(255, 255, 255, 0));
	square90.setFillColor(sf::Color(255, 255, 255, 0));
	square100.setFillColor(sf::Color(255, 255, 255, 0));
	//Declaration
	sf::Sprite dice;
	sf::Sprite dice1;
	sf::Sprite dice2;
	sf::Sprite dice3;
	sf::Sprite dice4;
	sf::Sprite dice5;
	sf::Sprite dice6;
	//bombs
	sf::Sprite bomb1;
	sf::Sprite bomb2;
	sf::Sprite bomb3;
	sf::Sprite bomb4;
	sf::Sprite bomb5;
	sf::Sprite bomb6;
	//end of bombs
	//rockets
	sf::Sprite rocket1;
	sf::Sprite rocket2;
	sf::Sprite rocket3;
	sf::Sprite rocket4;
	sf::Sprite rocket5;

	//end of rockets
	bomb1.setTexture(bomber);
	bomb2.setTexture(bomber);
	bomb3.setTexture(bomber);
	bomb4.setTexture(bomber);
	bomb5.setTexture(bomber);
	bomb6.setTexture(bomber);
	//
	rocket1.setTexture(rockets);
	rocket2.setTexture(rockets);
	rocket3.setTexture(rockets);
	rocket4.setTexture(rockets);
	rocket5.setTexture(rockets);

	//
	rocket1.setPosition(sf::Vector2f(810, 290));
	rocket2.setPosition(sf::Vector2f(510, 90));
	rocket3.setPosition(sf::Vector2f(610, 490));
	rocket4.setPosition(sf::Vector2f(210, 690));
	rocket5.setPosition(sf::Vector2f(10, 390));

	rocket1.setScale(sf::Vector2f(0.2, 0.2));
	rocket2.setScale(sf::Vector2f(0.2, 0.2));
	rocket3.setScale(sf::Vector2f(0.2, 0.2));
	rocket4.setScale(sf::Vector2f(0.2, 0.2));
	rocket5.setScale(sf::Vector2f(0.2, 0.2));

	bomb1.setScale(sf::Vector2f(0.2, 0.2));
	bomb2.setScale(sf::Vector2f(0.2, 0.2));
	bomb3.setScale(sf::Vector2f(0.2, 0.2));
	bomb4.setScale(sf::Vector2f(0.2, 0.2));
	bomb6.setScale(sf::Vector2f(0.2, 0.2));
	bomb5.setScale(sf::Vector2f(0.2, 0.2));

	//
	bomb1.setPosition(sf::Vector2f(210, 690));
	bomb2.setPosition(sf::Vector2f(510, 90));
	bomb3.setPosition(sf::Vector2f(810, 290));
	bomb4.setPosition(sf::Vector2f(610, 790));
	bomb5.setPosition(sf::Vector2f(110, 890));
	bomb6.setPosition(sf::Vector2f(10, 290));

	sf::Sprite sprite;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
	sf::Sprite sprite5;
	sf::Sprite sprite6;
	sf::Sprite sprite7;
	sf::Sprite sprite8;
	sf::Sprite sprite9;
	sf::Sprite sprite10;
	sf::Sprite playeer1;
	sf::Sprite computer1;
	sf::Sprite playeer2;
	sf::Sprite playeer3;
	sf::Sprite playeer4;
	sf::Sprite congrats;
	//end of declaration
	//textures
	//ladders
	sprite.setTexture(texture);
	sprite1.setTexture(texture2);
	sprite2.setTexture(texture2);
	sprite3.setTexture(texture2);
	sprite4.setTexture(texture2);
	sprite5.setTexture(texture2);
	//snakes


	sprite6.setTexture(texture3);
	sprite7.setTexture(texture3);
	sprite8.setTexture(texture3);
	sprite9.setTexture(texture3);
	sprite10.setTexture(texture3);
	playeer1.setTexture(playeeer8);
	playeer2.setTexture(playeeer1);
	playeer3.setTexture(playeeer9);
	playeer4.setTexture(playeeer10);
	computer1.setTexture(playeeer);
	congrats.setTexture(congratulations);
	//dice
	dice.setTexture(texture4);
	dice1.setTexture(dice_1);
	dice2.setTexture(dice_2);
	dice3.setTexture(dice_3);
	dice4.setTexture(dice_4);
	dice5.setTexture(dice_5);
	dice6.setTexture(dice_6);
	//dice position
	dice1.setPosition(sf::Vector2f(-700, -700));
	dice2.setPosition(sf::Vector2f(-700, -700));
	dice3.setPosition(sf::Vector2f(-700, -700));
	dice4.setPosition(sf::Vector2f(-700, -700));
	dice5.setPosition(sf::Vector2f(-700, -700));
	dice6.setPosition(sf::Vector2f(-700, -700));

	//end of dice
	//end of setting textures
	//rotation
	sprite1.rotate(35.f);
	sprite2.rotate(135.f);
	sprite3.rotate(60.f);
	sprite4.rotate(30.f);
	sprite5.rotate(5.f);
	sprite6.rotate(25.f);
	sprite7.rotate(25.f);
	sprite8.rotate(-20.f);
	sprite9.rotate(-35.f);
	sprite10.rotate(70.f);
	//square10.rotate(45.f);
	//end of rotation
	//scale
	sprite.setScale(sf::Vector2f(0.833, 0.83));
	sprite1.setScale(sf::Vector2f(0.2, 0.2));
	sprite2.setScale(sf::Vector2f(0.2, 0.2));
	sprite3.setScale(sf::Vector2f(0.2, 0.2));
	sprite4.setScale(sf::Vector2f(0.2, 0.2));
	sprite5.setScale(sf::Vector2f(0.2, 0.2));
	sprite6.setScale(sf::Vector2f(1.6, 1.6));
	sprite7.setScale(sf::Vector2f(1.2, 1.2));
	sprite8.setScale(sf::Vector2f(1.5, 1.5));
	sprite9.setScale(sf::Vector2f(1.7, 1.7));
	sprite10.setScale(sf::Vector2f(1.4, 1.4));
	playeer1.setScale(sf::Vector2f(0.7, 0.6));
	playeer2.setScale(sf::Vector2f(0.4, 0.5));
	playeer3.setScale(sf::Vector2f(0.4, 0.4));
	playeer4.setScale(sf::Vector2f(0.3, 0.4));
	computer1.setScale(sf::Vector2f(0.16, 0.16));
	square10.setScale(sf::Vector2f(1.5, 1.5));
	congrats.setScale(0.3, 0.3);
	//end of scale
	//position
	sprite1.setPosition(sf::Vector2f(900, 690));
	sprite2.setPosition(sf::Vector2f(600, 350));
	sprite3.setPosition(sf::Vector2f(600, 599));
	sprite4.setPosition(sf::Vector2f(155, 500));
	sprite5.setPosition(sf::Vector2f(940, 40));
	sprite6.setPosition(sf::Vector2f(200, 27));
	sprite7.setPosition(sf::Vector2f(800, 450));
	sprite8.setPosition(sf::Vector2f(600, 75));
	sprite9.setPosition(sf::Vector2f(220, 360));
	sprite10.setPosition(sf::Vector2f(530, 820));
	playeer1.setPosition(sf::Vector2f(-120, 900));
	playeer2.setPosition(sf::Vector2f(-120, 900));
	playeer3.setPosition(sf::Vector2f(-120, 900));
	playeer4.setPosition(sf::Vector2f(-120, 900));
	computer1.setPosition(sf::Vector2f(-120, 900));
	//player1.setSmooth
	//end of position

	//squares
	square10.setPosition(sf::Vector2f(700, 910));
	square20.setPosition(sf::Vector2f(10, 705));
	square30.setPosition(sf::Vector2f(310, 710));
	square40.setPosition(sf::Vector2f(810, 410));
	square50.setPosition(sf::Vector2f(215, 310));
	square60.setPosition(sf::Vector2f(510, 310));
	square70.setPosition(sf::Vector2f(910, 310));
	square80.setPosition(sf::Vector2f(210, 10));
	square90.setPosition(sf::Vector2f(610, 10));
	square100.setPosition(sf::Vector2f(510, 810));
	congrats.setPosition(-1100, -1100);


	int cnt = 2;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played1 == true && game_over == false)
		{
			if (grid[playerR][playerC] + dice_res <= 100)
			{

				if (playerC - dice_res < 0 && playerR % 2 == 0)
				{
					dice_res -= (playerC);
					playerC = 0;
					playerR--;
					dice_res--;
				}
				if (playerC + dice_res > 9 && playerR % 2 != 0 || playerC - dice_res > 9 && playerR % 2 == 0)
				{
					dice_res -= (9 - playerC);
					playerC += (9 - playerC);
					playerR--;
					dice_res--;
				}


				if (playerR % 2 != 0)
				{
					playerC += dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition(playerC * 100, playerR * 100);
					pressed = false;
				}
				else
				{
					playerC -= dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition((playerC * 100), playerR * 100);
					pressed = false;
				}
				cout << "R= " << playerR << endl;
				cout << "C= " << playerC << endl;
				switch (grid[playerR][playerC]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 94:
					playerR = 3;
					playerC = 7;

					break;


				case 98:
					playerR = 3;
					playerC = 1;

					break;


				case 63:
					playerR = 5;
					playerC = 4;

					break;


				case 52:
					playerR = 6;
					playerC = 7;

					break;


				case 15:
					playerR = 9;
					playerC = 2;

					break;


				case 70:
					playerR = 0;
					playerC = 9;

					break;


				case 66:
					playerR = 1;
					playerC = 3;

					break;


				case 21:
					playerR = 5;
					playerC = 1;

					break;


				case 24:
					playerR = 6;
					playerC = 6;

					break;


				case 8:
					playerR = 7;
					playerC = 9;

					break;


				default:
					break;
				}
				if (grid[playerR][playerC] == 100)
				{
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played1 = false;
			played2 = true;
			played3 = false;
			played4 = false;
		} ///end of player 1
		///player 2
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played2 == true && game_over == false)
		{
			if (grid[player2R][player2C] + dice_res <= 100)
			{

				if (player2C - dice_res < 0 && player2R % 2 == 0)
				{
					dice_res -= (player2C);
					player2C = 0;
					player2R--;
					dice_res--;
				}
				if (player2C + dice_res > 9 && player2R % 2 != 0 || player2C - dice_res > 9 && player2R % 2 == 0)
				{
					dice_res -= (9 - player2C);
					player2C += (9 - player2C);
					player2R--;
					dice_res--;
				}


				if (player2R % 2 != 0)
				{
					player2C += dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition(player2C * 100, player2R * 100);
					pressed = false;
				}
				else
				{
					player2C -= dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition((player2C * 100), player2R * 100);
					pressed = false;
				}
				cout << "R2= " << player2R << endl;
				cout << "C2= " << player2C << endl;
				switch (grid[player2R][player2C]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 94:
					player2R = 3;
					player2C = 7;

					break;


				case 98:
					player2R = 3;
					player2C = 1;

					break;


				case 63:
					player2R = 5;
					player2C = 4;

					break;


				case 52:
					player2R = 6;
					player2C = 7;

					break;


				case 15:
					player2R = 9;
					player2C = 2;

					break;


				case 70:
					player2R = 0;
					player2C = 9;

					break;


				case 66:
					player2R = 1;
					player2C = 3;

					break;


				case 21:
					player2R = 5;
					player2C = 1;

					break;


				case 24:
					player2R = 6;
					player2C = 6;

					break;


				case 8:
					player2R = 7;
					player2C = 9;

					break;


				default:
					break;
				}



				if (grid[player2R][player2C] == 100)
				{
					///congratulations
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played3 = true;
			played2 = false;
			played1 = false;
			played4 = false;
		}


		//
		///player 3
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played3 == true && game_over == false)
		{
			if (grid[player3R][player3C] + dice_res <= 100)
			{

				if (player3C - dice_res < 0 && player3R % 2 == 0)
				{
					dice_res -= (player3C);
					player3C = 0;
					player3R--;
					dice_res--;
				}
				if (player3C + dice_res > 9 && player3R % 2 != 0 || player3C - dice_res > 9 && player3R % 2 == 0)
				{
					dice_res -= (9 - player3C);
					player3C += (9 - player3C);
					player3R--;
					dice_res--;
				}


				if (player3R % 2 != 0)
				{
					player3C += dice_res;
					score = grid[player3R][player3C] - 1;
					cout << score << endl;
					playeer3.setPosition(player3C * 100, player3R * 100);
					pressed = false;
				}
				else
				{
					player3C -= dice_res;
					score = grid[player3R][player3C] - 1;
					cout << score << endl;
					playeer3.setPosition((player3C * 100), player2R * 100);
					pressed = false;
				}
				cout << "R3= " << player3R << endl;
				cout << "C3= " << player3C << endl;
				switch (grid[player3R][player3C]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 94:
					player3R = 3;
					player3C = 7;

					break;


				case 98:
					player3R = 3;
					player3C = 1;

					break;


				case 63:
					player3R = 5;
					player3C = 4;

					break;


				case 52:
					player3R = 6;
					player3C = 7;

					break;


				case 15:
					player3R = 9;
					player3C = 2;

					break;


				case 70:
					player3R = 0;
					player3C = 9;

					break;


				case 66:
					player3R = 1;
					player3C = 3;

					break;


				case 21:
					player3R = 5;
					player3C = 1;

					break;


				case 24:
					player3R = 6;
					player3C = 6;

					break;


				case 8:
					player3R = 7;
					player3C = 9;

					break;


				default:
					break;
				}



				if (grid[player3R][player3C] == 100)
				{
					///congratulations
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played4 = true;
			played2 = false;
			played3 = false;
			played1 = false;
		}


		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played4 == true && game_over == false)
		{
			if (grid[player4R][player4C] + dice_res <= 100)
			{

				if (player4C - dice_res < 0 && player4R % 2 == 0)
				{
					dice_res -= (player4C);
					player4C = 0;
					player4R--;
					dice_res--;
				}
				if (player4C + dice_res > 9 && player4R % 2 != 0 || player4C - dice_res > 9 && player4R % 2 == 0)
				{
					dice_res -= (9 - player4C);
					player4C += (9 - player4C);
					player4R--;
					dice_res--;
				}


				if (player4R % 2 != 0)
				{
					player4C += dice_res;
					score = grid[player4R][player4C] - 1;
					cout << score << endl;
					playeer4.setPosition(player4C * 100, player4R * 100);
					pressed = false;
				}
				else
				{
					player4C -= dice_res;
					score = grid[player4R][player4C] - 1;
					cout << score << endl;
					playeer4.setPosition((player4C * 100), player4R * 100);
					pressed = false;
				}
				cout << "R4= " << player4R << endl;
				cout << "C4= " << player4C << endl;
				switch (grid[player4R][player4C]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 94:
					player4R = 3;
					player4C = 7;

					break;


				case 98:
					player4R = 3;
					player4C = 1;

					break;


				case 63:
					player4R = 5;
					player4C = 4;

					break;


				case 52:
					player4R = 6;
					player4C = 7;

					break;


				case 15:
					player4R = 9;
					player4C = 2;

					break;


				case 70:
					player4R = 0;
					player4C = 9;

					break;


				case 66:
					player4R = 1;
					player4C = 3;

					break;


				case 21:
					player4R = 5;
					player4C = 1;

					break;


				case 24:
					player4R = 6;
					player4C = 6;

					break;


				case 8:
					player4R = 7;
					player4C = 9;

					break;


				default:
					break;
				}



				if (grid[player4R][player4C] == 100)
				{
					///congratulations
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played1 = true;
			played2 = false;
			played3 = false;
			played4 = false;
		}
		//
		cnt++;
		playeer1.setPosition(playerC * 100, playerR * 100);
		playeer2.setPosition(player2C * 100, player2R * 100);
		playeer3.setPosition(player3C * 100, player3R * 100);
		playeer4.setPosition(player4C * 100, player4R * 100);
		window.clear();
		window.draw(sprite);
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);
		window.draw(sprite8);
		window.draw(sprite9);
		window.draw(sprite10);
		window.draw(square10);
		window.draw(playeer1);
		window.draw(playeer2);
		window.draw(playeer3);
		window.draw(playeer4);
		window.draw(computer1);
		window.draw(square20);
		window.draw(square30);
		window.draw(square40);
		window.draw(square50);
		window.draw(square60);
		window.draw(square70);
		window.draw(square80);
		window.draw(square90);
		window.draw(square100);

		window.draw(dice1);
		window.draw(dice2);
		window.draw(dice3);
		window.draw(dice4);
		window.draw(dice5);
		window.draw(dice6);
		window.draw(congrats);
		window.display();
	}
}
void bomb() {
	int dice_res, playerR = 9, playerC = -1, player2R = 9, player2C = -1, score = 0;
	int player3R = 9, player3C = -1, player4R = 9, player4C = -1;
	bool pressed = false;
	bool played1 = true;
	bool played2 = false;
	bool played3 = false, played4 = false;
	bool game_over = false;
	////////////////////////////////////////////////
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "SnakePhobia");
	window.setKeyRepeatEnabled(false);
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture dice_1;
	sf::Texture dice_2;
	sf::Texture dice_3;
	sf::Texture dice_4;
	sf::Texture dice_5;
	sf::Texture dice_6;
	sf::Texture playeeer;
	sf::Texture playeeer1;
	sf::Texture congratulations;
	sf::Texture bomber;
	sf::Texture rockets;

	if (!texture.loadFromFile("numbered board.png"))
	{
		std::cout << "loading error" << std::endl;
	}

	if (!rockets.loadFromFile("bomb_PNG32.png"))
	{
		std::cout << "loading error" << std::endl;

	}

	if (!bomber.loadFromFile("Rocket-PNG-File.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer.loadFromFile("bird.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer1.loadFromFile("g.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture2.loadFromFile("LADDER_SPRITE.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture3.loadFromFile("57459272_638862999870607_5341563182932557824_n.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture4.loadFromFile("perspective-dice-six-faces-random.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_1.loadFromFile("dice-six-faces-one.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_2.loadFromFile("dice-six-faces-two.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_3.loadFromFile("dice-six-faces-three.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_4.loadFromFile("dice-six-faces-four.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_5.loadFromFile("dice-six-faces-five.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_6.loadFromFile("dice-six-faces-six.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!congratulations.loadFromFile("Congratulations.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	//shapes
	sf::RectangleShape square10(sf::Vector2f(60.f, 80.f));	//endofshapes
	sf::RectangleShape square20(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square30(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square40(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square50(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square60(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square70(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square80(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square90(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square100(sf::Vector2f(80.f, 80.f));

	square10.setFillColor(sf::Color(255, 255, 255, 0));
	square20.setFillColor(sf::Color(255, 255, 255, 0));
	square30.setFillColor(sf::Color(255, 255, 255, 0));
	square40.setFillColor(sf::Color(255, 255, 255, 0));
	square50.setFillColor(sf::Color(255, 255, 255, 0));
	square60.setFillColor(sf::Color(255, 255, 255, 0));
	square70.setFillColor(sf::Color(255, 255, 255, 0));
	square80.setFillColor(sf::Color(255, 255, 255, 0));
	square90.setFillColor(sf::Color(255, 255, 255, 0));
	square100.setFillColor(sf::Color(255, 255, 255, 0));
	//Declaration
	sf::Sprite dice;
	sf::Sprite dice1;
	sf::Sprite dice2;
	sf::Sprite dice3;
	sf::Sprite dice4;
	sf::Sprite dice5;
	sf::Sprite dice6;
	//bombs
	sf::Sprite bomb1;
	sf::Sprite bomb2;
	sf::Sprite bomb3;
	sf::Sprite bomb4;
	sf::Sprite bomb5;
	//end of bombs
	//rockets
	sf::Sprite rocket1;
	sf::Sprite rocket2;
	sf::Sprite rocket3;
	sf::Sprite rocket4;
	sf::Sprite rocket5;
	sf::Sprite rocket6;
	sf::Sprite rocket7;

	//end of rockets
	bomb1.setTexture(bomber);
	bomb2.setTexture(bomber);
	bomb3.setTexture(bomber);
	bomb4.setTexture(bomber);
	bomb5.setTexture(bomber);
	//
	rocket1.setTexture(rockets);
	rocket2.setTexture(rockets);
	rocket3.setTexture(rockets);
	rocket4.setTexture(rockets);
	rocket5.setTexture(rockets);
	rocket6.setTexture(rockets);
	rocket7.setTexture(rockets);

	//
	rocket1.setPosition(sf::Vector2f(810, 290));
	rocket2.setPosition(sf::Vector2f(510, 90));
	rocket3.setPosition(sf::Vector2f(610, 490));
	rocket4.setPosition(sf::Vector2f(210, 690));
	rocket5.setPosition(sf::Vector2f(10, 390));
	rocket6.setPosition(sf::Vector2f(610, 790));
	rocket7.setPosition(sf::Vector2f(210, 490));


	rocket1.setScale(sf::Vector2f(0.2, 0.2));
	rocket2.setScale(sf::Vector2f(0.2, 0.2));
	rocket3.setScale(sf::Vector2f(0.2, 0.2));
	rocket4.setScale(sf::Vector2f(0.2, 0.2));
	rocket5.setScale(sf::Vector2f(0.2, 0.2));
	rocket6.setScale(sf::Vector2f(0.2, 0.2));
	rocket7.setScale(sf::Vector2f(0.2, 0.2));

	//
	bomb1.setPosition(sf::Vector2f(-700, -700));
	bomb2.setPosition(sf::Vector2f(-700, -700));
	bomb3.setPosition(sf::Vector2f(-700, -700));
	bomb4.setPosition(sf::Vector2f(-700, -700));
	bomb5.setPosition(sf::Vector2f(-700, -700));

	sf::Sprite sprite;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
	sf::Sprite sprite5;
	sf::Sprite sprite6;
	sf::Sprite sprite7;
	sf::Sprite sprite8;
	sf::Sprite sprite9;
	sf::Sprite sprite10;
	sf::Sprite playeer1;
	sf::Sprite computer1;
	sf::Sprite playeer2;
	sf::Sprite playeer3;
	sf::Sprite playeer4;
	sf::Sprite congrats;
	//end of declaration
	//textures
	//ladders
	sprite.setTexture(texture);
	sprite1.setTexture(texture2);
	sprite2.setTexture(texture2);
	sprite3.setTexture(texture2);
	sprite4.setTexture(texture2);
	sprite5.setTexture(texture2);
	//snakes


	sprite6.setTexture(texture3);
	sprite7.setTexture(texture3);
	sprite8.setTexture(texture3);
	sprite9.setTexture(texture3);
	sprite10.setTexture(texture3);
	playeer1.setTexture(playeeer);
	playeer2.setTexture(playeeer1);
	playeer3.setTexture(playeeer);
	playeer4.setTexture(playeeer);
	computer1.setTexture(playeeer);
	congrats.setTexture(congratulations);
	//dice
	dice.setTexture(texture4);
	dice1.setTexture(dice_1);
	dice2.setTexture(dice_2);
	dice3.setTexture(dice_3);
	dice4.setTexture(dice_4);
	dice5.setTexture(dice_5);
	dice6.setTexture(dice_6);
	//dice position
	dice1.setPosition(sf::Vector2f(-700, -700));
	dice2.setPosition(sf::Vector2f(-700, -700));
	dice3.setPosition(sf::Vector2f(-700, -700));
	dice4.setPosition(sf::Vector2f(-700, -700));
	dice5.setPosition(sf::Vector2f(-700, -700));
	dice6.setPosition(sf::Vector2f(-700, -700));

	//end of dice
	//end of setting textures
	//rotation
	sprite1.rotate(35.f);
	sprite2.rotate(135.f);
	sprite3.rotate(60.f);
	sprite4.rotate(30.f);
	sprite5.rotate(5.f);
	sprite6.rotate(25.f);
	sprite7.rotate(25.f);
	sprite8.rotate(-20.f);
	sprite9.rotate(-35.f);
	sprite10.rotate(70.f);
	//square10.rotate(45.f);
	//end of rotation
	//scale
	sprite.setScale(sf::Vector2f(0.833, 0.83));
	sprite1.setScale(sf::Vector2f(0.2, 0.2));
	sprite2.setScale(sf::Vector2f(0.2, 0.2));
	sprite3.setScale(sf::Vector2f(0.2, 0.2));
	sprite4.setScale(sf::Vector2f(0.2, 0.2));
	sprite5.setScale(sf::Vector2f(0.2, 0.2));
	sprite6.setScale(sf::Vector2f(1.6, 1.6));
	sprite7.setScale(sf::Vector2f(1.2, 1.2));
	sprite8.setScale(sf::Vector2f(1.5, 1.5));
	sprite9.setScale(sf::Vector2f(1.7, 1.7));
	sprite10.setScale(sf::Vector2f(1.4, 1.4));
	playeer1.setScale(sf::Vector2f(0.5, 0.5));
	playeer2.setScale(sf::Vector2f(0.5, 0.5));///////////
	playeer3.setScale(sf::Vector2f(0.16, 0.16));
	playeer4.setScale(sf::Vector2f(0.16, 0.16));
	computer1.setScale(sf::Vector2f(0.16, 0.16));
	square10.setScale(sf::Vector2f(1.5, 1.5));
	congrats.setScale(0.3, 0.3);
	//end of scale
	//position
	sprite1.setPosition(sf::Vector2f(900, 690));
	sprite2.setPosition(sf::Vector2f(600, 350));
	sprite3.setPosition(sf::Vector2f(600, 599));
	sprite4.setPosition(sf::Vector2f(155, 500));
	sprite5.setPosition(sf::Vector2f(940, 40));
	sprite6.setPosition(sf::Vector2f(200, 27));
	sprite7.setPosition(sf::Vector2f(800, 450));
	sprite8.setPosition(sf::Vector2f(600, 75));
	sprite9.setPosition(sf::Vector2f(220, 360));
	sprite10.setPosition(sf::Vector2f(530, 820));
	playeer1.setPosition(sf::Vector2f(-120, 900));
	playeer2.setPosition(sf::Vector2f(-120, 900));
	playeer3.setPosition(sf::Vector2f(-120, 900));
	playeer4.setPosition(sf::Vector2f(-120, 900));
	computer1.setPosition(sf::Vector2f(-120, 900));
	//player1.setSmooth
	//end of position

	//squares
	square10.setPosition(sf::Vector2f(700, 910));
	square20.setPosition(sf::Vector2f(10, 705));
	square30.setPosition(sf::Vector2f(310, 710));
	square40.setPosition(sf::Vector2f(810, 410));
	square50.setPosition(sf::Vector2f(215, 310));
	square60.setPosition(sf::Vector2f(510, 310));
	square70.setPosition(sf::Vector2f(910, 310));
	square80.setPosition(sf::Vector2f(210, 10));
	square90.setPosition(sf::Vector2f(610, 10));
	square100.setPosition(sf::Vector2f(510, 810));
	congrats.setPosition(-1100, -1100);


	int cnt = 2;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played1 == true && game_over == false)
		{
			if (grid[playerR][playerC] + dice_res <= 100)
			{

				if (playerC - dice_res < 0 && playerR % 2 == 0)
				{
					dice_res -= (playerC);
					playerC = 0;
					playerR--;
					dice_res--;
				}
				if (playerC + dice_res > 9 && playerR % 2 != 0 || playerC - dice_res > 9 && playerR % 2 == 0)
				{
					dice_res -= (9 - playerC);
					playerC += (9 - playerC);
					playerR--;
					dice_res--;
				}


				if (playerR % 2 != 0)
				{
					playerC += dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition(playerC * 100, playerR * 100);
					pressed = false;
				}
				else
				{
					playerC -= dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition((playerC * 100), playerR * 100);
					pressed = false;
				}
				cout << "R= " << playerR << endl;
				cout << "C= " << playerC << endl;
				switch (grid[playerR][playerC]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 94:
					playerR = 3;
					playerC = 7;

					break;

				case 86:
					playerR = 9;
					playerC = 0;

					break;
				case 23:
					playerR = 9;
					playerC = 0;

					break;
				case 60:
					playerR = 9;
					playerC = 0;

					break;
				case 47:
					playerR = 9;
					playerC = 0;

					break;
				case 69:
					playerR = 9;
					playerC = 0;

					break;
				case 14:
					playerR = 9;
					playerC = 0;

					break;
				case 43:
					playerR = 9;
					playerC = 0;

					break;


				case 98:
					playerR = 3;
					playerC = 1;

					break;


				case 63:
					playerR = 5;
					playerC = 4;

					break;


				case 52:
					playerR = 6;
					playerC = 7;

					break;


				case 15:
					playerR = 9;
					playerC = 2;

					break;


				case 70:
					playerR = 0;
					playerC = 9;

					break;


				case 66:
					playerR = 1;
					playerC = 3;

					break;


				case 21:
					playerR = 5;
					playerC = 1;

					break;


				case 24:
					playerR = 6;
					playerC = 6;

					break;


				case 8:
					playerR = 7;
					playerC = 9;

					break;


				default:
					break;
				}
				if (grid[playerR][playerC] == 100)
				{
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played1 = false;
			played2 = true;
		} ///end of player 1
		///player 2
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));
					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played2 == true && game_over == false)
		{
			if (grid[player2R][player2C] + dice_res <= 100)
			{

				if (player2C - dice_res < 0 && player2R % 2 == 0)
				{
					dice_res -= (player2C);
					player2C = 0;
					player2R--;
					dice_res--;
				}
				if (player2C + dice_res > 9 && player2R % 2 != 0 || player2C - dice_res > 9 && player2R % 2 == 0)
				{
					dice_res -= (9 - player2C);
					player2C += (9 - player2C);
					player2R--;
					dice_res--;
				}


				if (player2R % 2 != 0)
				{
					player2C += dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition(player2C * 100, player2R * 100);
					pressed = false;
				}
				else
				{
					player2C -= dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition((player2C * 100), player2R * 100);
					pressed = false;
				}
				cout << "R2= " << player2R << endl;
				cout << "C2= " << player2C << endl;
				switch (grid[player2R][player2C]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 14:
					player2R = 9;
					player2C = 0;

					break;
				case 43:
					player2R = 9;
					player2C = 0;

					break;
				case 86:
					player2R = 9;
					player2C = 0;

					break;
				case 23:
					player2R = 9;
					player2C = 0;

					break;
				case 60:
					player2R = 9;
					player2C = 0;

					break;
				case 47:
					player2R = 9;
					player2C = 0;

					break;
				case 69:
					player2R = 9;
					player2C = 0;

					break;
				case 94:
					player2R = 3;
					player2C = 7;

					break;


				case 98:
					player2R = 3;
					player2C = 1;

					break;


				case 63:
					player2R = 5;
					player2C = 4;

					break;


				case 52:
					player2R = 6;
					player2C = 7;

					break;


				case 15:
					player2R = 9;
					player2C = 2;

					break;


				case 70:
					player2R = 0;
					player2C = 9;

					break;


				case 66:
					player2R = 1;
					player2C = 3;

					break;


				case 21:
					player2R = 5;
					player2C = 1;

					break;


				case 24:
					player2R = 6;
					player2C = 6;

					break;


				case 8:
					player2R = 7;
					player2C = 9;

					break;


				default:
					break;
				}



				if (grid[player2R][player2C] == 100)
				{
					///congratulations
					congrats.setPosition(1100, 50);
					game_over = true;
				}
			}
			played1 = true;
			played2 = false;
		}
		cnt++;
		playeer1.setPosition(playerC * 100, playerR * 100);
		playeer2.setPosition(player2C * 100, player2R * 100);

		window.clear();

		window.draw(sprite);
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);
		window.draw(sprite8);
		window.draw(sprite9);
		window.draw(sprite10);
		window.draw(square10);
		window.draw(playeer1);
		window.draw(playeer2);
		window.draw(computer1);
		window.draw(square20);
		window.draw(square30);
		window.draw(square40);
		window.draw(square50);
		window.draw(square60);
		window.draw(square70);
		window.draw(square80);
		window.draw(square90);
		window.draw(square100);

		window.draw(dice1);
		window.draw(dice2);
		window.draw(dice3);
		window.draw(dice4);
		window.draw(dice5);
		window.draw(dice6);

		window.draw(rocket1);
		window.draw(rocket2);
		window.draw(rocket3);
		window.draw(rocket4);
		window.draw(rocket5);
		window.draw(rocket6);
		window.draw(rocket7);

		window.draw(congrats);
		window.display();
	}

}
void rocket() {
	int dice_res, playerR = 9, playerC = -1, player2R = 9, player2C = -1, score = 0;
	int player3R = 9, player3C = -1, player4R = 9, player4C = -1;
	bool pressed = false;
	bool played1 = true;
	bool played2 = false;
	bool played3 = false, played4 = false;
	bool game_over = false;
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "SnakePhobia");
	window.setKeyRepeatEnabled(false);
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture dice_1;
	sf::Texture dice_2;
	sf::Texture dice_3;
	sf::Texture dice_4;
	sf::Texture dice_5;
	sf::Texture dice_6;
	sf::Texture playeeer;
	sf::Texture playeeer1;
	sf::Texture congratulations;
	sf::Texture bomber;
	sf::Texture rockets;

	if (!texture.loadFromFile("numbered board.png"))
	{
		std::cout << "loading error" << std::endl;
	}

	if (!rockets.loadFromFile("bomb_PNG32.png"))
	{
		std::cout << "loading error" << std::endl;

	}

	if (!bomber.loadFromFile("Rocket-PNG-File.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer.loadFromFile("bird.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!playeeer1.loadFromFile("g.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture2.loadFromFile("LADDER_SPRITE.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture3.loadFromFile("57459272_638862999870607_5341563182932557824_n.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!texture4.loadFromFile("perspective-dice-six-faces-random.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_1.loadFromFile("dice-six-faces-one.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_2.loadFromFile("dice-six-faces-two.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_3.loadFromFile("dice-six-faces-three.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_4.loadFromFile("dice-six-faces-four.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_5.loadFromFile("dice-six-faces-five.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!dice_6.loadFromFile("dice-six-faces-six.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	if (!congratulations.loadFromFile("Congratulations.png"))
	{
		std::cout << "loading error" << std::endl;
	}
	//shapes
	sf::RectangleShape square10(sf::Vector2f(60.f, 80.f));	//endofshapes
	sf::RectangleShape square20(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square30(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square40(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square50(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square60(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square70(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square80(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square90(sf::Vector2f(80.f, 80.f));
	sf::RectangleShape square100(sf::Vector2f(80.f, 80.f));

	square10.setFillColor(sf::Color(255, 255, 255, 0));
	square20.setFillColor(sf::Color(255, 255, 255, 0));
	square30.setFillColor(sf::Color(255, 255, 255, 0));
	square40.setFillColor(sf::Color(255, 255, 255, 0));
	square50.setFillColor(sf::Color(255, 255, 255, 0));
	square60.setFillColor(sf::Color(255, 255, 255, 0));
	square70.setFillColor(sf::Color(255, 255, 255, 0));
	square80.setFillColor(sf::Color(255, 255, 255, 0));
	square90.setFillColor(sf::Color(255, 255, 255, 0));
	square100.setFillColor(sf::Color(255, 255, 255, 0));
	//Declaration
	sf::Sprite dice;
	sf::Sprite dice1;
	sf::Sprite dice2;
	sf::Sprite dice3;
	sf::Sprite dice4;
	sf::Sprite dice5;
	sf::Sprite dice6;
	//bombs
	sf::Sprite bomb1;
	sf::Sprite bomb2;
	sf::Sprite bomb3;
	sf::Sprite bomb4;
	sf::Sprite bomb5;
	sf::Sprite bomb6;
	//end of bombs
	//rockets
	sf::Sprite rocket1;
	sf::Sprite rocket2;
	sf::Sprite rocket3;
	sf::Sprite rocket4;
	sf::Sprite rocket5;

	//end of rockets
	bomb1.setTexture(bomber);
	bomb2.setTexture(bomber);
	bomb3.setTexture(bomber);
	bomb4.setTexture(bomber);
	bomb5.setTexture(bomber);
	bomb6.setTexture(bomber);
	//
	rocket1.setTexture(rockets);
	rocket2.setTexture(rockets);
	rocket3.setTexture(rockets);
	rocket4.setTexture(rockets);
	rocket5.setTexture(rockets);

	//
	rocket1.setPosition(sf::Vector2f(810, 290));
	rocket2.setPosition(sf::Vector2f(510, 90));
	rocket3.setPosition(sf::Vector2f(610, 490));
	rocket4.setPosition(sf::Vector2f(210, 690));
	rocket5.setPosition(sf::Vector2f(10, 390));

	rocket1.setScale(sf::Vector2f(0.2, 0.2));
	rocket2.setScale(sf::Vector2f(0.2, 0.2));
	rocket3.setScale(sf::Vector2f(0.2, 0.2));
	rocket4.setScale(sf::Vector2f(0.2, 0.2));
	rocket5.setScale(sf::Vector2f(0.2, 0.2));

	bomb1.setScale(sf::Vector2f(0.2, 0.2));
	bomb2.setScale(sf::Vector2f(0.2, 0.2));
	bomb3.setScale(sf::Vector2f(0.2, 0.2));
	bomb4.setScale(sf::Vector2f(0.2, 0.2));
	bomb6.setScale(sf::Vector2f(0.2, 0.2));
	bomb5.setScale(sf::Vector2f(0.2, 0.2));

	//
	bomb1.setPosition(sf::Vector2f(210, 690));
	bomb2.setPosition(sf::Vector2f(510, 90));
	bomb3.setPosition(sf::Vector2f(810, 290));
	bomb4.setPosition(sf::Vector2f(610, 790));
	bomb5.setPosition(sf::Vector2f(110, 890));
	bomb6.setPosition(sf::Vector2f(10, 290));

	sf::Sprite sprite;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
	sf::Sprite sprite5;
	sf::Sprite sprite6;
	sf::Sprite sprite7;
	sf::Sprite sprite8;
	sf::Sprite sprite9;
	sf::Sprite sprite10;
	sf::Sprite playeer1;
	sf::Sprite computer1;
	sf::Sprite playeer2;
	sf::Sprite playeer3;
	sf::Sprite playeer4;
	sf::Sprite congrats;
	//end of declaration
	//textures
	//ladders
	sprite.setTexture(texture);
	sprite1.setTexture(texture2);
	sprite2.setTexture(texture2);
	sprite3.setTexture(texture2);
	sprite4.setTexture(texture2);
	sprite5.setTexture(texture2);
	//snakes


	sprite6.setTexture(texture3);
	sprite7.setTexture(texture3);
	sprite8.setTexture(texture3);
	sprite9.setTexture(texture3);
	sprite10.setTexture(texture3);
	playeer1.setTexture(playeeer);
	playeer2.setTexture(playeeer1);
	playeer3.setTexture(playeeer);
	playeer4.setTexture(playeeer);
	computer1.setTexture(playeeer);
	congrats.setTexture(congratulations);
	//dice
	dice.setTexture(texture4);
	dice1.setTexture(dice_1);
	dice2.setTexture(dice_2);
	dice3.setTexture(dice_3);
	dice4.setTexture(dice_4);
	dice5.setTexture(dice_5);
	dice6.setTexture(dice_6);
	//dice position
	dice1.setPosition(sf::Vector2f(-700, -700));
	dice2.setPosition(sf::Vector2f(-700, -700));
	dice3.setPosition(sf::Vector2f(-700, -700));
	dice4.setPosition(sf::Vector2f(-700, -700));
	dice5.setPosition(sf::Vector2f(-700, -700));
	dice6.setPosition(sf::Vector2f(-700, -700));

	//end of dice
	//end of setting textures
	//rotation
	sprite1.rotate(35.f);
	sprite2.rotate(135.f);
	sprite3.rotate(60.f);
	sprite4.rotate(30.f);
	sprite5.rotate(5.f);
	sprite6.rotate(25.f);
	sprite7.rotate(25.f);
	sprite8.rotate(-20.f);
	sprite9.rotate(-35.f);
	sprite10.rotate(70.f);
	//square10.rotate(45.f);
	//end of rotation
	//scale
	sprite.setScale(sf::Vector2f(0.833, 0.83));
	sprite1.setScale(sf::Vector2f(0.2, 0.2));
	sprite2.setScale(sf::Vector2f(0.2, 0.2));
	sprite3.setScale(sf::Vector2f(0.2, 0.2));
	sprite4.setScale(sf::Vector2f(0.2, 0.2));
	sprite5.setScale(sf::Vector2f(0.2, 0.2));
	sprite6.setScale(sf::Vector2f(1.6, 1.6));
	sprite7.setScale(sf::Vector2f(1.2, 1.2));
	sprite8.setScale(sf::Vector2f(1.5, 1.5));
	sprite9.setScale(sf::Vector2f(1.7, 1.7));
	sprite10.setScale(sf::Vector2f(1.4, 1.4));
	playeer1.setScale(sf::Vector2f(0.5, 0.5));
	playeer2.setScale(sf::Vector2f(0.5, 0.5));
	playeer3.setScale(sf::Vector2f(0.16, 0.16));
	playeer4.setScale(sf::Vector2f(0.16, 0.16));
	computer1.setScale(sf::Vector2f(0.16, 0.16));
	square10.setScale(sf::Vector2f(1.5, 1.5));
	congrats.setScale(0.3, 0.3);
	//end of scale
	//position
	sprite1.setPosition(sf::Vector2f(900, 690));
	sprite2.setPosition(sf::Vector2f(600, 350));
	sprite3.setPosition(sf::Vector2f(600, 599));
	sprite4.setPosition(sf::Vector2f(155, 500));
	sprite5.setPosition(sf::Vector2f(940, 40));
	sprite6.setPosition(sf::Vector2f(200, 27));
	sprite7.setPosition(sf::Vector2f(800, 450));
	sprite8.setPosition(sf::Vector2f(600, 75));
	sprite9.setPosition(sf::Vector2f(220, 360));
	sprite10.setPosition(sf::Vector2f(530, 820));
	playeer1.setPosition(sf::Vector2f(-120, 900));
	playeer2.setPosition(sf::Vector2f(-120, 900));
	playeer3.setPosition(sf::Vector2f(-120, 900));
	playeer4.setPosition(sf::Vector2f(-120, 900));
	computer1.setPosition(sf::Vector2f(-120, 900));
	//player1.setSmooth
	//end of position

	//squares
	square10.setPosition(sf::Vector2f(700, 910));
	square20.setPosition(sf::Vector2f(10, 705));
	square30.setPosition(sf::Vector2f(310, 710));
	square40.setPosition(sf::Vector2f(810, 410));
	square50.setPosition(sf::Vector2f(215, 310));
	square60.setPosition(sf::Vector2f(510, 310));
	square70.setPosition(sf::Vector2f(910, 310));
	square80.setPosition(sf::Vector2f(210, 10));
	square90.setPosition(sf::Vector2f(610, 10));
	square100.setPosition(sf::Vector2f(510, 810));
	congrats.setPosition(-1100, -1100);


	int cnt = 2;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played1 == true && game_over == false)
		{
			if (grid[playerR][playerC] + dice_res <= 100)
			{

				if (playerC - dice_res < 0 && playerR % 2 == 0)
				{
					dice_res -= (playerC);
					playerC = 0;
					playerR--;
					dice_res--;
				}
				if (playerC + dice_res > 9 && playerR % 2 != 0 || playerC - dice_res > 9 && playerR % 2 == 0)
				{
					dice_res -= (9 - playerC);
					playerC += (9 - playerC);
					playerR--;
					dice_res--;
				}


				if (playerR % 2 != 0)
				{
					playerC += dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition(playerC * 100, playerR * 100);
					pressed = false;
				}
				else
				{
					playerC -= dice_res;
					score = grid[playerR][playerC] - 1;
					cout << score << endl;
					playeer1.setPosition((playerC * 100), playerR * 100);
					pressed = false;
				}
				cout << "R= " << playerR << endl;
				cout << "C= " << playerC << endl;





				switch (grid[playerR][playerC]) // it is snakes and ladders, numbers represent the snakes and ladders
				{
				case 94:
					playerR = 3;
					playerC = 7;

					break;

				case 14:
					playerR = 3;
					playerC = 8;

					break;
				case 23:
					playerR = 1;
					playerC = 5;

					break;
				case 2:
					playerR = 0;
					playerC = 3;

					break;

				case 98:
					playerR = 3;
					playerC = 1;

					break;


				case 63:
					playerR = 5;
					playerC = 4;

					break;


				case 52:
					playerR = 6;
					playerC = 7;

					break;


				case 15:
					playerR = 9;
					playerC = 2;

					break;


				case 70:
					playerR = 0;
					playerC = 9;

					break;


				case 66:
					playerR = 1;
					playerC = 3;

					break;


				case 21:
					playerR = 5;
					playerC = 1;

					break;


				case 24:
					playerR = 6;
					playerC = 6;

					break;


				case 8:
					playerR = 7;
					playerC = 9;

					break;


				default:
					break;
				}




				if (grid[playerR][playerC] == 100)
				{
					congrats.setPosition(1100, 50);//////////////////////////////////////
					game_over = true;
				}
			}
			played1 = false;
			played2 = true;
		} ///end of player 1



		///player 2
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space))

			{
				dice_res = dice_roll();
				if (dice_res == 1)
				{
					dice1.setPosition(sf::Vector2f(1100, 500));

					dice2.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}

				else  if (dice_res == 2)
				{
					dice2.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 3)
				{
					dice3.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 4)
				{
					dice4.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 5)
				{
					dice5.setPosition(sf::Vector2f(1100, 500));

					dice1.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					//dice5.setPosition(sf::Vector2f(-700,- 700));
					dice6.setPosition(sf::Vector2f(-700, -700));

				}
				else  if (dice_res == 6)
				{
					dice6.setPosition(sf::Vector2f(1100, 500));


					dice1.setPosition(sf::Vector2f(-700, -700));
					//dice2.setPosition(sf::Vector2f(-300, -300));
					dice3.setPosition(sf::Vector2f(-700, -700));
					dice4.setPosition(sf::Vector2f(-700, -700));
					dice5.setPosition(sf::Vector2f(-700, -700));
					dice2.setPosition(sf::Vector2f(-700, -700));

					//dice6.setPosition(sf::Vector2f(-300,- 300));
				}

				cout << dice_res << endl;
				pressed = true;
			}
		}
		if (pressed == true && played2 == true && game_over == false)
		{
			if (grid[player2R][player2C] + dice_res <= 100)
			{

				if (player2C - dice_res < 0 && player2R % 2 == 0)
				{
					dice_res -= (player2C);
					player2C = 0;
					player2R--;
					dice_res--;
				}
				if (player2C + dice_res > 9 && player2R % 2 != 0 || player2C - dice_res > 9 && player2R % 2 == 0)
				{
					dice_res -= (9 - player2C);
					player2C += (9 - player2C);
					player2R--;
					dice_res--;
				}


				if (player2R % 2 != 0)
				{
					player2C += dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition(player2C * 100, player2R * 100);
					pressed = false;
				}
				else
				{
					player2C -= dice_res;
					score = grid[player2R][player2C] - 1;
					cout << score << endl;
					playeer2.setPosition((player2C * 100), player2R * 100);
					pressed = false;
				}
				cout << "R2= " << player2R << endl;
				cout << "C2= " << player2C << endl;





				switch (grid[player2R][player2C]) // it is snakes and ladders, numbers represent the snakes and ladders
				{

				case 14:
					player2R = 3;
					player2C = 8;

					break;
				case 23:
					player2R = 1;
					player2C = 5;

					break;
				case 2:
					player2R = 0;
					player2C = 3;

					break;

				case 94:
					player2R = 3;
					player2C = 7;

					break;


				case 98:
					player2R = 3;
					player2C = 1;

					break;


				case 63:
					player2R = 5;
					player2C = 4;

					break;


				case 52:
					player2R = 6;
					player2C = 7;

					break;


				case 15:
					player2R = 9;
					player2C = 2;

					break;


				case 70:
					player2R = 0;
					player2C = 9;

					break;


				case 66:
					player2R = 1;
					player2C = 3;

					break;


				case 21:
					player2R = 5;
					player2C = 1;

					break;


				case 24:
					player2R = 6;
					player2C = 6;

					break;


				case 8:
					player2R = 7;
					player2C = 9;

					break;


				default:
					break;
				}



				if (grid[player2R][player2C] == 100)
				{
					///congratulations
					congrats.setPosition(1100, 50);////////////////////////////
					game_over = true;
				}
			}
			played1 = true;
			played2 = false;
		}
		cnt++;
		playeer1.setPosition(playerC * 100, playerR * 100);
		playeer2.setPosition(player2C * 100, player2R * 100);

		window.clear();

		window.draw(sprite);
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);
		window.draw(sprite8);
		window.draw(sprite9);
		window.draw(sprite10);
		window.draw(square10);
		window.draw(playeer1);
		window.draw(playeer2);
		window.draw(computer1);
		window.draw(square20);
		window.draw(square30);
		window.draw(square40);
		window.draw(square50);
		window.draw(square60);
		window.draw(square70);
		window.draw(square80);
		window.draw(square90);
		window.draw(square100);

		window.draw(dice1);
		window.draw(dice2);
		window.draw(dice3);
		window.draw(dice4);
		window.draw(dice5);
		window.draw(dice6);
		window.draw(bomb1);
		window.draw(bomb2);
		window.draw(bomb3);
		window.draw(bomb4);
		window.draw(bomb5);
		window.draw(bomb6);
		window.draw(congrats);
		window.display();
	}

}
int start_player() {
	int Selected_player_indx = 0;
	if (open == true) {
		music.play();
	}
	//music.setLoop(true);
	Text playerss[num_of_players];
	Font font2;
	font2.loadFromFile("font3.ttf");
	playerss[0].setFont(font2);
	playerss[0].setFillColor(Color::White);
	playerss[0].setString("2 players");
	playerss[0].setPosition(Vector2f(478, 270));
	playerss[0].setCharacterSize(90);

	playerss[1].setFont(font2);
	playerss[1].setFillColor(Color::White);
	playerss[1].setString("3 players");
	playerss[1].setPosition(Vector2f(478, 530));
	playerss[1].setCharacterSize(90);

	playerss[2].setFont(font2);
	playerss[2].setFillColor(Color::White);
	playerss[2].setString("4 players");
	playerss[2].setPosition(Vector2f(478, 770));
	playerss[2].setCharacterSize(90);
	while (window7.isOpen())
	{
		sf::Event event;
		while (window7.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window7.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::M:
					music.stop();
					break;
				case::Keyboard::O:
					music.play();
					break;
				case sf::Keyboard::Up:
					if (Selected_player_indx - 1 >= 0) {
						playerss[Selected_player_indx].setFillColor(Color::White);
						Selected_player_indx--;
						playerss[Selected_player_indx].setFillColor(Color::Red);
					}
					break;

				case sf::Keyboard::Down:
					if (Selected_player_indx + 1 < num_of_players) {
						playerss[Selected_player_indx].setFillColor(Color::White);
						Selected_player_indx++;
						playerss[Selected_player_indx % num_of_players].setFillColor(Color::Red);
					}
					break;
				case ::Keyboard::Enter:
					return Selected_player_indx;
					break;
				}
			}
			Sprite playersbackground;
			Texture players;
			window7.clear();
			players.loadFromFile("hhhh.png");
			playersbackground.scale(1.5, 1.3);
			playersbackground.setTexture(players);

			Font chooseplayers;
			chooseplayers.loadFromFile("font3.ttf");
			Text player;

			player.setFont(chooseplayers);
			player.setString(" Players :)");
			player.setFillColor(Color(255, 250, 200));
			player.setCharacterSize(120);
			player.setPosition(Vector2f(430, 0));


			window7.draw(playersbackground);
			window7.draw(player);

			for (int i = 0; i < num_of_players; i++)
			{
				window7.draw(playerss[i]);
			}
			window7.display();
		}
	}
}
int choosedifficulty() {
	int Selected_difficulty_indx = 0;
	Text difficultyy[num_of_difficulty];
	Font font2;
	font2.loadFromFile("font3.ttf");
	difficultyy[0].setFont(font2);
	difficultyy[0].setFillColor(Color::White);
	difficultyy[0].setString("Easy");
	difficultyy[0].setPosition(Vector2f(430, 350));
	difficultyy[0].setCharacterSize(130);

	difficultyy[1].setFont(font2);
	difficultyy[1].setFillColor(Color::White);
	difficultyy[1].setString("Hard");
	difficultyy[1].setPosition(Vector2f(430, 500));
	difficultyy[1].setCharacterSize(130);


	if (open == true) {
		music.play();
	}
	//music.setPitch(2); BYSR3 ELSOT
	//music.setLoop(true); //btfdl sh8alaaaaaaaa tol el3ba 

	while (window7.isOpen())
	{
		sf::Event event;
		while (window7.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window7.close();
				break;
			case ::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::M:
					music.stop();
					open = false;
					break;
				case::Keyboard::O:
					music.play();
					open = true;
					break;

				case sf::Keyboard::Up:
					if (Selected_difficulty_indx - 1 >= 0) {
						difficultyy[Selected_difficulty_indx].setFillColor(Color::White);
						Selected_difficulty_indx--;
						difficultyy[Selected_difficulty_indx].setFillColor(Color::Red);
					}
					break;

				case sf::Keyboard::Down:
					if (Selected_difficulty_indx + 1 < num_of_levels) {
						difficultyy[Selected_difficulty_indx].setFillColor(Color::White);
						Selected_difficulty_indx++;
						difficultyy[Selected_difficulty_indx % num_of_levels].setFillColor(Color::Red);
					}
					break;
				case ::Keyboard::Enter:
					return Selected_difficulty_indx;
					break;
				}
			}
			Sprite difficultbackground;
			Texture diff;
			diff.setSmooth(true);
			diff.loadFromFile("difficulty.png");
			difficultbackground.setScale(1.5, 1.3);
			difficultbackground.setTexture(diff);

			Text difficulty;
			difficulty.setFont(font2);
			difficulty.setString("Difficulty");
			difficulty.setFillColor(Color::Yellow);
			difficulty.setCharacterSize(200);
			difficulty.setPosition(Vector2f(360, 80));


			window7.clear();
			window7.draw(difficultbackground);
			window7.draw(difficulty);
			for (int i = 0; i < num_of_difficulty; i++)
			{
				window7.draw(difficultyy[i]);
			}
			window7.display();

		}
	}
}
void start_play() {
	int MyChoise = startmenu();
	if (MyChoise == 0)/////////////// das play fa hyft7  elevels bs mmkn a5ly levels
	{
		int choise = start_level();
		if (choise == 0) {   /////////////// hna lw a5tar el level one
			int num = start_player();//hyft7 el window kam player
			////////////////// hna hynady function ashakl elplayer
			if (num == 0) { // lw a5tar 2 players
				level1_2playerss();
			}
			else if (num == 1) {/////// hnaa lw 3 playersss;
				level1_3players();
			}
			else if (num == 2) {/////// hna lw 4 playerssss;
				level1_4players();
			}
		}
		if (choise == 1) {
			//////////////hna hyft7 windoo rocket aw bomb
			int difficult;
			difficult = choosedifficulty();
			if (difficult == 1) { ///bomb
				bomb();
			}
			else if (difficult == 0) {///rocket
					////////////////////////////////////////////////
				rocket();
				//startmenu();
			}
		}
	}
	if (MyChoise == 1)
	{
		if (open == true) {
			music.play();
		}
		while (window7.isOpen())
		{

			sf::Event event;

			while (window7.pollEvent(event))
			{
				switch (event.type)
				{

				case sf::Event::Closed:
					window7.close();
					break;
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
					case sf::Keyboard::M:
						music.stop();
						break;
					case::Keyboard::O:
						music.play();
						break;
					}
				}
			}
			Sprite about;
			Texture aboutphoto;
			aboutphoto.loadFromFile("about pic.png");
			about.setTexture(aboutphoto);
			about.setScale(Vector2f(0.9, 1));
			window7.clear();
			window7.draw(about);
			window7.display();
		}
	}

}
int continuee() {
	int Selected_level_indx = 0;
	Text levelss[num_of_levels];
	Font font2;
	font2.loadFromFile("font3.ttf");
	levelss[0].setFont(font2);
	levelss[0].setFillColor(Color::White);
	levelss[0].setString("YES");
	levelss[0].setPosition(Vector2f(430, 350));
	levelss[0].setCharacterSize(130);

	levelss[1].setFont(font2);
	levelss[1].setFillColor(Color::White);
	levelss[1].setString("NO");
	levelss[1].setPosition(Vector2f(430, 600));
	levelss[1].setCharacterSize(130);


	if (open == true) {
		music.play();
	}
	//music.setPitch(2); BYSR3 ELSOT
	//music.setLoop(true); //btfdl sh8alaaaaaaaa tol el3ba 

	while (window7.isOpen())
	{
		sf::Event event;
		while (window7.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window7.close();
				break;
			case ::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::M:
					music.stop();
					open = false;
					break;
				case::Keyboard::O:
					music.play();
					open = true;
					break;

				case sf::Keyboard::Up:
					if (Selected_level_indx - 1 >= 0) {
						levelss[Selected_level_indx].setFillColor(Color::White);
						Selected_level_indx--;
						levelss[Selected_level_indx].setFillColor(Color::Red);
					}
					break;

				case sf::Keyboard::Down:
					if (Selected_level_indx + 1 < num_of_levels) {
						levelss[Selected_level_indx].setFillColor(Color::White);
						Selected_level_indx++;
						levelss[Selected_level_indx % num_of_levels].setFillColor(Color::Red);
					}
					break;
				case ::Keyboard::Enter:
					return Selected_level_indx;
					break;
				}
			}
			Sprite levelsbackground;
			Texture levels;
			levels.setSmooth(true);
			levels.loadFromFile("Untitled.png");
			levelsbackground.setScale(1.5, 1.3);
			levelsbackground.setTexture(levels);

			Text Levels;
			Levels.setFont(font2);
			Levels.setString("Do you want to continue !");
			Levels.setFillColor(Color::Yellow);
			Levels.setCharacterSize(120);
			Levels.setPosition(Vector2f(50, 10));


			window7.clear();
			window7.draw(levelsbackground);
			window7.draw(Levels);
			for (int i = 0; i < num_of_levels; i++)
			{
				window7.draw(levelss[i]);
			}
			window7.display();

		}
	}
}
int main() {
	int yy = 150, xx = 700, b;
	bool pressd = false;
	bool nextpressed = false;
	//vector<string>names;
	start_play();
	while (true) {
		b = continuee();
		if (b == 1) {
			window7.close();
			break;
		}
		else {
			start_play();
		}
	}
	return 0;

}