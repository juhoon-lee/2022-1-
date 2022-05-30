-- 고객 테이블 생성
create table customer
	(c_ID	varchar(15), 
	name	varchar(30),
  address	varchar(30), 
	phone	numeric(11,0), 
  point numeric(3,0),
  coupon numeric(3,0),
	primary key (c_ID) 
	);

-- 물품 테이블 생성
create table product
	(p_ID	varchar(15), 
	p_name varchar(20),
  kind varchar(30), 
	price	numeric(11,0), 
  avg_grade numeric(3,0),
  stock numeric(3,0),
	primary key (p_ID) 
	);

-- 장바구니 목록 테이블 생성
create table bucket_list
	(c_ID	varchar(15), 
	b_ID varchar(15),
	primary key (b_ID) 
	);

-- 장바구니 내역 테이블 생성
create table bucket_detail
  (b_ID varchar(15),
  p_ID varchar(15),
  purchase_count numeric(10,0),
  primary key (b_ID, p_ID) 
  );

-- 구매확정 테이블 생성
create table purchased
  (b_ID varchar(15),
  purchased_date numeric(10,0),
  primary key (b_ID) 
  );

-- 환불내역 테이블 생성
create table refund
  (b_ID varchar(15),
  purchased_date numeric(10,0),
  p_ID varchar(15),
  purchase_count numeric(10,0),
  primary key (b_ID, purchased_date, p_ID) 
  );


-- 평가 테이블 생성
create table ㄷvaluation
  (c_ID	varchar(15), 
  p_ID varchar(15),
  grade numeric(3,0),
  review varchar(100),
  primary key (c_ID, p_ID) 
  );