I = imread('C:\Users\mishr\Desktop\Project Part 1\serial_code\New_Image_Circles.tiff');
tic
J = imresize(I, 10, 'nearest');
toc
t=toc;
disp(t);
tic
L = imresize(I, 10, 'bilinear');
toc
t=toc;
disp(t);
figure
imshow(I)
title('Original Image')
figure
imshow(J)
title('Nearest Neighbor Interpolated Image')
figure
imshow(L)
title('Bilinear Interpolated Image')
