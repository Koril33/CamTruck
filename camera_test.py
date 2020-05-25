import cv2
import os

def open_camera():
    capture = cv2.VideoCapture(0)
    capture.set(3, 480)

    while capture.isOpened():
        flag, image = capture.read()
        image = cv2.flip(image, -1)
        cv2.imshow("image", image)
        k = cv2.waitKey(1)

        if k == ord('s'):
            cv2.imwrite('testCamera.jpg', image)

        elif k == ord('q'):
            break

    capture.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    open_camera()
