#include "../../Monocle.h"
#include "../../TextureAsset.h"
#include "../../Graphics/Sprite.h"
#include <string>
#include <vector>

using namespace Monocle;

namespace Flash
{
	class Texture
	{
	public:
		Texture(){}
		std::string name;
		std::string path;
		int width, height;
		Vector2 registrationPoint;
	};

	class TextureSheet
	{
	public:
		TextureSheet(){}
		Texture* GetTextureByName(const std::string &name);

		std::string name;
		std::vector<Texture> textures;
	};

	class Frame
	{
	public:
		Frame()
			: pos(pos), scale(scale), alpha(1.0f), hasScaleData(false)
		{}
		Vector2 pos;
		Vector2 scale;
		float alpha;
		bool hasScaleData;
	};

	class Part
	{
	public:
		Part(const std::string &name)
			: name(name), entity(NULL), sprite(NULL)
		{}
		std::string name;
		std::vector<Frame> frames;

		Entity *CreateEntity(TextureSheet &textureSheet);
		void Update(float frame);

		Entity *entity;
		Sprite *sprite;
	};

	class Animation
	{
	public:
		Animation(const std::string &name, int frameCount)
			: name(name), frameCount(frameCount)
		{}
		int GetMaxFrames();
		std::string name;
		int frameCount;
		std::vector<Part> parts;
		
	};

	/*
	class OnionSkinning
	{
	public:
		OnionSkinning();
	};
	*/

	class TestScene : public Scene
	{
	public:
		void Begin();
		void Update();
		
	private:
		void LoadAnimation(const std::string &filename);
		void LoadTextureSheet(const std::string &filename);
		void InitAnimation(Animation *animation, Entity *eParent);
		void Play(Animation *animation, float fps);
		void Pause();
		void Resume();
		void UpdateAnimation(Animation *animation);
		void OffsetFramesBy(const Vector2 &offset);
		void GoPrevFrame(int num=1);
		void GoNextFrame(int num=1);
		void ApplyFrame();
		void SelectPrevPart();
		void SelectNextPart();

		std::vector<Animation> animations;
		TextureSheet textureSheet;
		Animation *playingAnimation;
		bool isPlaying;
		bool isEditing;
		bool isRecording;
		int selectedPartIndex;
		float animationFrame;
		float fps;


		
	};
}