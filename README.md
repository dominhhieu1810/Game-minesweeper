
GAME DÒ MÌN INT2215 21 - Đỗ Minh Hiếu - 19021273. 
Có sử dụng struct, thư viện cstdlib để dùng hàm rand(), thư viện ctime để dùng hàm time(), SDL_ttf.h và font chữ Bitstream Vera Sans Mono.
Cách chơi:
- Khi vào game sẽ khởi tạo mặc đinh level dễ.
- Góc phía trên bên trái sẽ có 3 ô tùy chọn mức độ khó của trò chơi.
- Góc phía trên bên phải là số kí tự "?" để đánh dấu ô nghi có mìn còn lại(luôn nhỏ hơn hoặc bằng số mìn), click chuột trái vào ô chưa mở để đánh dấu, double click vào ô đã đánh dấu để xóa dấu.
- Những ô đã mở có hiện số chính là số mìn có trong 8 ô xung quanh ô đó;
- Khi thắng hoặc thua sẽ có 3 giây để hiên kết quá sau đó game sẽ khởi tạo lại như lúc đầu với mức level bạn đã chọn. Bạn có thể chọn chơi tiếp hoặc thoát game.