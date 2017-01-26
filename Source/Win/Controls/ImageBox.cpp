#include "ImageBox.hpp"

namespace Goo
{
	void ImageBox::CreateControl() {
		CreateHandle("STATIC", "", SS_BITMAP);
		SetImage(image);
	}
	
	void ImageBox::SetImage(const Image& image_) {
		::SendMessage(GetHandle(), STM_SETIMAGE,
				IMAGE_BITMAP, (LPARAM)(HBITMAP)(image_.GetHandle()));
		image = image_;
	}
}
