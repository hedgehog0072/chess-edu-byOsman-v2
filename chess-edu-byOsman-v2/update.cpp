#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

#include <cmath> 
extern SDL_Renderer* renderer;
int kare = 60;
void Indexler();
int tahta(int x, int y);
bool sorgu(int x, int y);
int sorguD(int x, int y);
struct tas
{
public:
	int x1 = 0;
	int y1 = 0;
protected:
	SDL_Surface* surfaceMessageT = nullptr;
	SDL_Rect Message_rect; //create a rect
	SDL_Texture* Message;
	std::string isim;
	bool beyaz;

	void UInit(int xI, int yI, std::string isimI, bool beyazI)
	{
		beyaz = beyazI;
		if (beyaz)
		{
			isimI += "b.png";

		}
		else
		{
			isimI += "s.png";

		}
		isim = isimI;

		x1 = xI;
		y1 = yI;
		render();

	}
	//render
public:
	void render()
	{
		surfaceMessageT = IMG_Load(isim.c_str());
		Message = SDL_CreateTextureFromSurface(renderer, surfaceMessageT);

		Message_rect.x = 0 + x1 * kare;  //controls the rect's x coordinate 
		Message_rect.y = 0 + y1 * kare; // controls the rect's y coordinte
		Message_rect.w = kare; // controls the width of the rect
		Message_rect.h = kare; // controls the height of the rect

		SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	}
	void tasDelete()
	{
		UInit(-1, -1, "123123", true);


	}

};

struct piyon : tas       /////// NOTE(OSMAN) ==         PIYONDAN VEZIR CIKARMA EKLENMEDI !!!!!!!!!
{
	bool bonus = true;
	void Init(int xI, int yI, bool beyaz)
	{
		UInit(xI, yI, "P", beyaz);


	}

	void haraket(int x2, int y2)
	{
		try
		{

			if (beyaz)
			{
				if (y2 == y1 - 2 && x2 == x1 && bonus && !sorgu(x2, y2) && !sorgu(x2, y2 + 1))
				{
					tahta(x1, y1);
					x1 = x2;
					y1 = y2;

					tahta(x1, y1);

					render();
					bonus = false;
					return;


				}

				if (y2 == y1 - 1 && (x2 == x1 + 1 || x2 == x1 + -1) && sorgu(x2, y2))
				{
					sorguD(x2, y2);
					tahta(x1, y1);
					x1 = x2;
					y1 = y2;

					tahta(x1, y1);

					render();
					return;
				}

				if (y2 == y1 - 1 && x2 == x1 && !sorgu(x2, y2))
				{
					tahta(x1, y1);
					x1 = x2;
					y1 = y2;

					tahta(x1, y1);

					render();
					return;

				}
				throw "HATALI HAMLE";

			}




			else
			{
				if (y2 == y1 + 2 && x2 == x1 && bonus && !sorgu(x2, y2) && !sorgu(x2, y2 - 1))
				{
					tahta(x1, y1);
					x1 = x2;
					y1 = y2;

					tahta(x1, y1);

					render();
					bonus = false;
					return;


				}

				if (y2 == y1 + 1 && (x2 == x1 + 1 || x2 == x1 + -1) && sorgu(x2, y2))
				{
					sorguD(x2, y2);
					tahta(x1, y1);
					x1 = x2;
					y1 = y2;

					tahta(x1, y1);

					render();
					return;
				}
				if (y2 == y1 + 1 && x2 == x1 && !sorgu(x2, y2))
				{

					tahta(x1, y1);
					x1 = x2;
					y1 = y2;

					tahta(x1, y1);

					render();
					return;

				}
				throw "HATALI HAMLE";
			}

		}
		catch (const char* x)
		{
			std::cout << "[ERROR] = " << x << std::endl;
		}



	}




};
struct kale : tas
{
	void Init(int xI, int yI, bool beyaz)
	{
		UInit(xI, yI, "K", beyaz);

	}

	void haraket(int x2, int y2)
	{
		try
		{


			if (x1 != x2 && y1 == y2)
			{
				if (x2 < x1)
				{
					for (int i = x2; i < x1 - 1; i++)
					{
						if (sorgu(i, y1))
							throw "HATALI HAMLE";
					}
				}
				else
				{
					for (int i = x1 + 1; i < x2; i++)
					{
						if (sorgu(i, y1))
							throw "HATALI HAMLE";
					}
				}
				sorguD(x2, y2);
				tahta(x1, y1);
				x1 = x2;
				y1 = y2;
				tahta(x1, y1);

				render();
				return;
			}

			if (x1 == x2 && y1 != y2)
			{
				if (y2 < y1)
				{
					for (int i = y2; i < y1; i++)
					{
						if (sorgu(x1, i))
							throw "HATALI HAMLE";
					}
				}
				else
				{
					for (int i = y1 + 1; i < y2; i++)
					{
						if (sorgu(x1, i))
							throw "HATALI HAMLE";
					}

				}
				sorguD(x2, y2);
				tahta(x1, y1);
				x1 = x2;
				y1 = y2;
				tahta(x1, y1);

				render();
				return;
			}
			throw "HATALI HAMLE";


		}
		catch (const char* x)
		{
			std::cout << "[ERROR] = " << x << std::endl;
		}


	}


};
struct at : tas
{
	void Init(int xI, int yI, bool beyaz)
	{
		UInit(xI, yI, "A", beyaz);

	}

	void haraket(int x2, int y2)
	{

		tahta(x1, y1);
		x1 = x2;
		y1 = y2;
		tahta(x1, y1);

		render();


	}

};
struct fil : tas
{
	void Init(int xI, int yI, bool beyaz)
	{
		UInit(xI, yI, "F", beyaz);

	}

	void haraket(int x2, int y2)
	{



		try
		{
			if (std::abs(x2 - x1) == std::abs(y2 - y1))
			{
				if (x2 > x1)
				{
					if (y2 > y1)
					{
						int i = 0;
						while (x2 - 1 - i != x1 && y2 - 1 - i != y1)
						{

							if (sorgu(x2 - 1 - i, y2 - 1 - i))
								throw "HATALI HAMLE";
							i++;

						}
					}
					else
					{

						int i = 0;
						while (x2 - 1 - i != x1 && y2 + 1 + i != y1)
						{

							if (sorgu(x2 - 1 - i, y2 + 1 + i))
								throw "HATALI HAMLE";
							i++;

						}
					}
				}
				else if (y2 > y1)
				{
					int i = 0;
					while (x2 + 1 + i != x1 && y2 - 1 - i != y1)
					{

						if (sorgu(x2 + 1 + i, y2 - 1 - i))
							throw "HATALI HAMLE";
						i++;

					}
				}

				else
				{
					int i = 0;
					while (x2 + 1 + i != x1 && y2 + 1 + i != y1)
					{

						if (sorgu(x2 + 1 + i, y2 + 1 + i))
							throw "HATALI HAMLE";
						i++;

					}
				}



				sorguD(x2, y2);
				tahta(x1, y1);
				x1 = x2;
				y1 = y2;
				tahta(x1, y1);

				render();
				return;

			}
			throw "HATALI HAMLE";




		}

		catch (const char* x)
		{
			std::cout << "[ERROR] = " << x << std::endl;
		}



	}

};
struct vezir : tas
{
	void Init(int xI, int yI, bool beyaz)
	{
		UInit(xI, yI, "V", beyaz);

	}

	void haraket(int x2, int y2)
	{

		tahta(x1, y1);
		x1 = x2;
		y1 = y2;
		tahta(x1, y1);

		render();


	}

};

struct sah : tas
{
	void Init(int xI, int yI, bool beyaz)
	{
		UInit(xI, yI, "S", beyaz);

	}

	void haraket(int x2, int y2)
	{

		tahta(x1, y1);
		x1 = x2;
		y1 = y2;

		tahta(x1, y1);

		render();


	}

};



bool beyazRenk = true;
SDL_Surface* surfaceMessage = nullptr;
int kareX = 0;
int kareY = 0;
piyon piyonlar[16];
kale kaleler[4];
at atlar[4];
fil filler[4];
vezir vezirler[2];
sah sahlar[2];
void tahta()
{

	static bool done = false;
	if (!done)
	{


		Indexler();
		for (int i = 0; i < 64; i++)
		{

			if (beyazRenk)
			{
				surfaceMessage = IMG_Load("beyazKare.png");
				beyazRenk = (!beyazRenk);

			}
			else
			{
				surfaceMessage = IMG_Load("siyahKare.png");
				beyazRenk = !beyazRenk;

			}


			SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

			SDL_Rect Message_rect; //create a rect
			Message_rect.x = kareX;  //controls the rect's x coordinate 
			Message_rect.y = kareY; // controls the rect's y coordinte
			Message_rect.w = kare; // controls the width of the rect
			Message_rect.h = kare; // controls the height of the rect

			SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

			kareX += kare;
			if (kareX == 8 * kare)
			{
				kareX = 0;
				kareY += kare;
				beyazRenk = !beyazRenk;

			}

		}
		for (int a = 0; a < 2; a++)
		{

			for (int i = 0; i < 8; i++)
			{
				static int x = 0;

				piyonlar[x].Init(i, 1 + 5 * a, a);
				x++;

			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 2; i++)
			{
				static int x = 0;

				kaleler[x].Init(0 + i * 7, 7 * a, a);
				x++;
			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 2; i++)
			{
				static int x = 0;

				atlar[x].Init(1 + i * 5, 7 * a, a);
				x++;
			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 2; i++)
			{
				static int x = 0;

				filler[x].Init(2 + i * 3, 7 * a, a);
				x++;
			}
		}
		for (int a = 0; a < 2; a++)
		{
			vezirler[a].Init(3, 7 * a, a);

		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 2; i++)
			{
				sahlar[a].Init(4, 7 * a, a);
			}
		}
		done = true;
	}
}
bool piyonlarH = false;
bool kalelerH = false;
bool atlarH = false;
bool fillerH = false;
bool vezirlerH = false;
bool sahlarH = false;
int sorguH(int x, int y)
{
	int deneme;
	for (deneme = 0; deneme < sizeof(piyonlar) / sizeof(piyon); deneme++)
	{
		if (piyonlar[deneme].x1 == x && piyonlar[deneme].y1 == y)
		{
			piyonlarH = true;
			return deneme;

		}

	}
	for (deneme = 0; deneme < sizeof(kaleler) / sizeof(kale); deneme++)
	{
		if (kaleler[deneme].x1 == x && kaleler[deneme].y1 == y)
		{
			kalelerH = true;
			return deneme;
		}

	}
	for (deneme = 0; deneme < sizeof(atlar) / sizeof(at); deneme++)
	{
		if (atlar[deneme].x1 == x && atlar[deneme].y1 == y)
		{
			atlarH = true;
			return deneme;
		}

	}
	for (deneme = 0; deneme < sizeof(filler) / sizeof(kale); deneme++)
	{
		if (filler[deneme].x1 == x && filler[deneme].y1 == y)
		{
			fillerH = true;
			return deneme;
		}

	}
	for (deneme = 0; deneme < sizeof(vezirler) / sizeof(kale); deneme++)
	{
		if (vezirler[deneme].x1 == x && vezirler[deneme].y1 == y)
		{
			vezirlerH = true;
			return deneme;
		}

	}
	for (deneme = 0; deneme < sizeof(sahlar) / sizeof(kale); deneme++)
	{
		if (sahlar[deneme].x1 == x && sahlar[deneme].y1 == y)
		{
			sahlarH = true;
			return deneme;
		}

	}

	return -1;

}
bool sorgu(int x, int y)
{
	int deneme;
	for (deneme = 0; deneme < sizeof(piyonlar) / sizeof(piyon); deneme++)
	{
		if (piyonlar[deneme].x1 == x && piyonlar[deneme].y1 == y)
		{

			return true;

		}

	}
	for (deneme = 0; deneme < sizeof(kaleler) / sizeof(kale); deneme++)
	{
		if (kaleler[deneme].x1 == x && kaleler[deneme].y1 == y)
		{
			return true;
		}

	}
	for (deneme = 0; deneme < sizeof(atlar) / sizeof(at); deneme++)
	{
		if (atlar[deneme].x1 == x && atlar[deneme].y1 == y)
		{
			return true;
		}

	}
	for (deneme = 0; deneme < sizeof(filler) / sizeof(kale); deneme++)
	{
		if (filler[deneme].x1 == x && filler[deneme].y1 == y)
		{
			return true;
		}

	}
	for (deneme = 0; deneme < sizeof(vezirler) / sizeof(kale); deneme++)
	{
		if (vezirler[deneme].x1 == x && vezirler[deneme].y1 == y)
		{
			return true;
		}

	}
	for (deneme = 0; deneme < sizeof(sahlar) / sizeof(kale); deneme++)
	{
		if (sahlar[deneme].x1 == x && sahlar[deneme].y1 == y)
		{
			return true;
		}

	}

	return false;

}

int sorguD(int x, int y)
{
	int denemeD;
	for (denemeD = 0; denemeD < sizeof(piyonlar) / sizeof(piyon); denemeD++)
	{
		if (piyonlar[denemeD].x1 == x && piyonlar[denemeD].y1 == y)
		{

			piyonlar[denemeD].tasDelete();
			return denemeD;

		}

	}
	for (denemeD = 0; denemeD < sizeof(kaleler) / sizeof(kale); denemeD++)
	{
		if (kaleler[denemeD].x1 == x && kaleler[denemeD].y1 == y)
		{
			kaleler[denemeD].tasDelete();
			return denemeD;
		}

	}
	for (denemeD = 0; denemeD < sizeof(atlar) / sizeof(at); denemeD++)
	{
		if (atlar[denemeD].x1 == x && atlar[denemeD].y1 == y)
		{
			atlar[denemeD].tasDelete();
			return denemeD;
		}

	}
	for (denemeD = 0; denemeD < sizeof(filler) / sizeof(kale); denemeD++)
	{
		if (filler[denemeD].x1 == x && filler[denemeD].y1 == y)
		{
			filler[denemeD].tasDelete();
			return denemeD;
		}

	}
	for (denemeD = 0; denemeD < sizeof(vezirler) / sizeof(kale); denemeD++)
	{
		if (vezirler[denemeD].x1 == x && vezirler[denemeD].y1 == y)
		{
			vezirler[denemeD].tasDelete();
			return denemeD;
		}

	}
	for (denemeD = 0; denemeD < sizeof(sahlar) / sizeof(kale); denemeD++)
	{
		if (sahlar[denemeD].x1 == x && sahlar[denemeD].y1 == y)
		{
			sahlar[denemeD].tasDelete();
			return denemeD;
		}

	}

	return -1;

}


void Indexler()
{
	TTF_Init();
	for (int a = 0; a < 8; a++)
	{
		TTF_Font* Sans;
		Sans = TTF_OpenFont("bold.ttf", 16);
		//TTF_OpenFontIndex("arial.ttf", 16, 0);


		if (!Sans) {
			printf("TTF_OpenFont: %s\n", TTF_GetError());
			// handle error
		}
		const char* harf[8] = { "A","B","C","D","E","F","G","H" };
		SDL_Color White = { 255, 255, 255 };

		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, harf[a], White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

		SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

		SDL_Rect Message_rect; //create a rect
		Message_rect.x = 0 + kare * a;  //controls the rect's x coordinate 
		Message_rect.y = 8 * kare; // controls the rect's y coordinte
		Message_rect.w = kare; // controls the width of the rect
		Message_rect.h = kare; // controls the height of the rect

		SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

		// sadsadsadasddddddddsadsad

		if (a == 1)
		{
			SDL_Color Red = { 255,0,0 };
			surfaceMessage = TTF_RenderText_Solid(Sans, "Welcome", Red);
			Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture
			Message_rect.x = kare * 10;
			Message_rect.y = kare * 3;
			Message_rect.w = kare * 3;
			Message_rect.h = kare * 2;

			SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

		}

	}



	for (int a = 0; a < 8; a++)

	{
		TTF_Font* Sans;
		Sans = TTF_OpenFont("bold.ttf", 16);
		//TTF_OpenFontIndex("arial.ttf", 16, 0);


		if (!Sans) {
			printf("TTF_OpenFont: %s\n", TTF_GetError());
			// handle error
		}
		const char* rakam[8] = { "1","2","3","4","5","6","7","8" };
		SDL_Color White = { 255, 255, 255 };

		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, rakam[a], White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

		SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

		SDL_Rect Message_rect; //create a rect
		Message_rect.x = 8 * kare;  //controls the rect's x coordinate 
		Message_rect.y = 7 * kare - kare * a; // controls the rect's y coordinte
		Message_rect.w = kare; // controls the width of the rect
		Message_rect.h = kare; // controls the height of the rect

		SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

	}

}


int tahta(int x, int y)
{



	if ((x + y) % 2 == 0)
	{
		surfaceMessage = IMG_Load("beyazKare.png");
		beyazRenk = (!beyazRenk);

	}
	else
	{
		surfaceMessage = IMG_Load("siyahKare.png");
		beyazRenk = !beyazRenk;

	}


	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = x * kare;  //controls the rect's x coordinate 
	Message_rect.y = y * kare; // controls the rect's y coordinte
	Message_rect.w = kare; // controls the width of the rect
	Message_rect.h = kare; // controls the height of the rect

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture


	return 0;
}


bool haraket = false;

////////**********   HARD CODE   ////////**********   
static int deneme = 0;
int xB;
int yB;
void clickDown(int x1, int y1)
{

	xB = x1 / kare;
	yB = y1 / kare;

	if (sorguH(xB, yB) != -1)
	{
		deneme = sorguH(xB, yB);
	}
	//std::cout << sizeof(piyon) << std::endl;

}

void clickUp(int x1, int y1)
{
	int x = x1 / kare;
	int y = y1 / kare;
	if (xB == x && yB == y)
	{
		return;
	}

	if (piyonlarH)
	{
		piyonlar[deneme].haraket(x, y);
		piyonlarH = false;
	}
	if (kalelerH)
	{
		kaleler[deneme].haraket(x, y);
		kalelerH = false;
	}
	if (atlarH)
	{
		atlar[deneme].haraket(x, y);
		atlarH = false;
	}if (fillerH)
	{
		filler[deneme].haraket(x, y);
		fillerH = false;
	}if (vezirlerH)
	{
		vezirler[deneme].haraket(x, y);
		vezirlerH = false;
	}if (sahlarH)
	{
		sahlar[deneme].haraket(x, y);
		sahlarH = false;

	}

}


