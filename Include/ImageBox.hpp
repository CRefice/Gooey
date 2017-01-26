#pragma once

#include "Control.hpp"
#include "Image.hpp"

namespace Goo
{
class ImageBox : public Control
{
public: 
	ImageBox() : Control(), image() {}
	ImageBox(const Image& image) : image(image), Control() {}
	ImageBox(const Image& image, const Point& pos, const Size& size) : image(image), Control(pos, size) {}

	void CreateControl() override;

	void SetImage(const Image& image_);
	Image GetImage() const { return image; }

private:
	Image image;
};
}
