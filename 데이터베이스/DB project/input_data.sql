-- 고객 데이터 입력
insert into customer values ('1','juhoon','incheon',01011111111,0,0);
insert into customer values ('2','jingi','paju',01022222222,0,0);
insert into customer values ('3','minheok','busan',01033333333,0,0);
insert into customer values ('4','changwoo','sokcho',01044444444,0,0);
insert into customer values ('5','chanheoung','jeju',01055555555,0,0);

-- 물품 입력
insert into product values ('a1','백미','곡류',2000,0,10);
insert into product values ('a2','보리','곡류',2200,0,10);
insert into product values ('a3','현미','곡류',2800,0,10);
insert into product values ('a4','흑미','곡류',2500,0,10);
insert into product values ('a5','잡곡','곡류',3000,0,10);

insert into product values ('b1','상추','채소',1500,0,10);
insert into product values ('b2','감자','채소',5000,0,10);
insert into product values ('b3','깻잎','채소',1800,0,10);
insert into product values ('b4','양파','채소',3000,0,10);
insert into product values ('b5','마늘','채소',2000,0,10);

insert into product values ('c1','사과','과일',1000,0,10);
insert into product values ('c2','귤','과일',500,0,10);
insert into product values ('c3','수박','과일',8000,0,10);
insert into product values ('c4','바나나','과일',5000,0,10);
insert into product values ('c5','포도','과일',4000,0,10);

insert into product values ('d1','안심','고기',10000,0,10);
insert into product values ('d2','등심','고기',9000,0,10);
insert into product values ('d3','양지','고기',8000,0,10);
insert into product values ('d4','차돌','고기',15000,0,10);
insert into product values ('d5','양념갈비','고기',13000,0,10);

-- 장바구니 입력
insert into bucket_list values ('1','bk_1');
insert into bucket_list values ('1','bk_2');
insert into bucket_list values ('2','bk_3');
insert into bucket_list values ('2','bk_4');
insert into bucket_list values ('3','bk_5');
insert into bucket_list values ('3','bk_6');
insert into bucket_list values ('4','bk_7');
insert into bucket_list values ('4','bk_8');
insert into bucket_list values ('5','bk_9');
insert into bucket_list values ('5','bk_10');

-- 장바구니 내역 입력
-- bk_1은 빈 장바구니
-- bk_2,3은 1개
-- 나머지 3개 이상
insert into bucket_detail values ('bk_2','b2',4);

insert into bucket_detail values ('bk_3','c4',2);

insert into bucket_detail values ('bk_4','d5',1);
insert into bucket_detail values ('bk_4','c2',2);
insert into bucket_detail values ('bk_4','a3',5);

insert into bucket_detail values ('bk_5','b3',7);
insert into bucket_detail values ('bk_5','c2',2);
insert into bucket_detail values ('bk_5','c3',1);

insert into bucket_detail values ('bk_6','d4',2);
insert into bucket_detail values ('bk_6','d5',1);
insert into bucket_detail values ('bk_6','a5',3);

insert into bucket_detail values ('bk_7','d1',4);
insert into bucket_detail values ('bk_7','a4',2);
insert into bucket_detail values ('bk_7','c5',3);

insert into bucket_detail values ('bk_8','c4',3);
insert into bucket_detail values ('bk_8','d3',2);
insert into bucket_detail values ('bk_8','a1',6);

insert into bucket_detail values ('bk_9','c5',3);
insert into bucket_detail values ('bk_9','c4',3);
insert into bucket_detail values ('bk_9','c3',4);

insert into bucket_detail values ('bk_10','a2',3);
insert into bucket_detail values ('bk_10','b2',7);
insert into bucket_detail values ('bk_10','d5',2);

-- 구매확정 내역 입력
insert into purchased values ('bk_7','22.05.20',0); -- ID 4가 구매 및 평가
insert into evaluation values ('4','d1',3,'부드러워요');
insert into evaluation values ('4','a4',5,'건강해여');
insert into evaluation values ('4','c5',2,'달지 않아요');

insert into purchased values ('bk_2','22.05.21',0); -- ID 1이 구매 및 평가
insert into evaluation values ('1','b2',5,'너무 좋아요');

insert into purchased values ('bk_9','22.05.25',0); -- ID 5가 구매 및 평가
insert into evaluation values ('5','c3',4,'싱싱해요.');
insert into evaluation values ('5','c4',5,'맛있어요.');
insert into evaluation values ('5','c5',4,'알이 많아요');

insert into purchased values ('bk_3','22.06.02',0); -- ID 2가 구매 및 평가
insert into evaluation values ('2','c4',3,'그냥 그래요');
insert into evaluation values ('2','d5',1,'질겨요');
insert into evaluation values ('2','a3',5,'너무 좋아요');

insert into purchased values ('bk_5','22.06.03',0); -- ID 3이 구매 및 평가
insert into evaluation values ('3','b3',3,'나쁘지 않아요');
insert into evaluation values ('3','c2',1,'맛없어요');
insert into evaluation values ('3','c3',4,'달아요');

insert into purchased values ('bk_6','22.06.05',0); -- ID 3이 구매 및 평가
insert into evaluation values ('3','d4',2,'지방이 많아요');
insert into evaluation values ('3','d5',5,'아주 맛 좋아요');
insert into evaluation values ('3','a5',5,'건강해지는 것 같아요');

insert into purchased values ('bk_8','22.06.05',1); -- ID 4가 구매 및 평가
insert into evaluation values ('4','c4',4,'대박 달아요');
insert into evaluation values ('4','a1',3,'적당해요');

insert into purchased values ('bk_10','22.06.20',1); -- ID 5가 구매 및 평가
insert into evaluation values ('5','a2',2,'딱딱해요');
insert into evaluation values ('5','b2',4,'꿀맛');

-- 환불 내역 입력
insert into refund values ('bk_1','22.05.23',0);
insert into refund values ('bk_1','22.05.23',0);
insert into refund values ('bk_1','22.05.23',0);



