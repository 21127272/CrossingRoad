#include "GameSound.h";

bool Sound::isSoundEnabled() {
	return soundEnabled;
}

void Sound::setSoundEnabled(bool enable) {
	soundEnabled = enable;
}

void Sound::playBackgroundSound(bool enable) {
	if (enable)
		PlaySound(TEXT("LegendaryAmadeus.wav"), NULL, SND_ASYNC);
	else
		PlaySound(NULL, NULL, SND_ASYNC);

}

void Sound::endGameSound() {
	PlaySound(NULL, NULL, SND_FILENAME);

}

void Sound::playPlayerMoveSound() {
	PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);

}
void Sound::playSuccessSound() {
	PlaySound(TEXT("Success.wav"), NULL, SND_ASYNC);

}
void Sound::playWinSound() {
	PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
}
void Sound::playLoseSound() {
	PlaySound(TEXT("lose.wav"), NULL, SND_ASYNC);
}