<!DOCTYPE html>
<html lang="zh-Hant-TW">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>書店Demo</title>
    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css">
    <!-- Bootstrap 圖標 -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.8.1/font/bootstrap-icons.css">
    <!-- 自定義 CSS -->
    <link href="css/bookshop.css" rel="stylesheet">
    <!-- boxIcons -->
    <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>
</head>

<body class="dark-theme">
    <!-- 固定位置的物件放在最上面 -->
    <i class='bx bx-moon bx-rotate-270 themeIcon' id="themeIcon"></i>
    <nav class="navbar navbar-expand-lg navbar-dark fixed-top">
        <div class="container-fluid">
            <!--標題頁面 -->
            <a class="navbar-brand fs-2" href="index.php">
                <img src="images/book.png" alt="" class="d-inline-block  align-text-top">
                閱緣書坊
            </a>
            <!-- 切換按鈕 -->
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavDropdown"
                aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <!-- 向外的連結, 向右排列 -->
            <div class="collapse navbar-collapse justify-content-end" id="navbarNavDropdown">
                <ul class="navbar-nav">
                    <!-- me-3 代表增加間隔 -->
                    <!-- fs-3 代表增大字體  -->
                    <li class="nav-item title-nav me-3 fs-5">
                        <div class="d-flex align-items-center">
                            <a class="nav-link" href="login.html"><i class='bx bx-user'></i>登入</a>
                            <span>|</span>
                            <a class="nav-link" href="register.html">註冊</a>
                        </div>
                    </li>
                    <li class="nav-item title-nav me-3 fs-5">

                    </li>
                    <li class="nav-item title-nav me-3 fs-5">
                        <a class="nav-link" href="#"><i class="bx bx-home me-1"></i>會員中心</a>
                    </li>
                    <li class="nav-item title-nav me-3 fs-5">
                        <a class="nav-link" href="#"><i class="bx bx-cart me-1"></i>購物車</a>
                    </li>
                    <li class="nav-item title-nav me-3 fs-5">
                        <a class="nav-link" href="#"><i class="bx bx-book-open me-1"></i>電子書櫃</a>
                    </li>
                </ul>
            </div>
        </div>
    </nav>
    <main>
        <section class="container">
            <!-- 廣告輪播區域 -->
            <div class="slider-wrapper mt-10vh">
                <div class="slider">
                    <!-- 廣告圖片 -->
                    <img id="slide-1"
                        src="https://images.unsplash.com/photo-1712417827761-7a68ff4a90f3?q=80&w=2670&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D"
                        alt="slider 1">
                    <img id="slide-2"
                        src="https://plus.unsplash.com/premium_photo-1709311394823-8b0856db0bcc?q=80&w=1171&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D"
                        alt="slider 2">
                    <img id="slide-3"
                        src="https://images.unsplash.com/photo-1654859869130-fd0a2aa5539b?q=80&w=1228&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D"
                        alt="slider 3">
                </div>
                <!-- 廣告輪播按鈕 -->
                <div class="slider-nav">
                    <a data-index="0"></a>
                    <a data-index="1"></a>
                    <a data-index="2"></a>
                </div>
                <!-- 上一頁箭頭按鈕 -->
                <a class="prev-arrow fs-2"><i class='bx bx-chevron-left'></i></a>
                <!-- 下一頁箭頭按鈕 -->
                <div class="next-arrow fs-2"><i class='bx bx-chevron-right'></i></div>
            </div>
        </section>
        <div class="container mt-5">
            <!-- 篩選區域 -->
            <div class="row mb-4">
                <div class="col-md-6">
                    <div class="dropdown">
                        <button class="btn btn-secondary dropdown-toggle" type="button" id="dropdownMenuButton"
                            data-bs-toggle="dropdown" aria-expanded="false">
                            選擇分類
                        </button>
                        <ul class="dropdown-menu" aria-labelledby="dropdownMenuButton">
                            <li><a class="dropdown-item" href="#">分類 1</a></li>
                            <li><a class="dropdown-item" href="#">分類 2</a></li>
                            <li><a class="dropdown-item" href="#">分類 3</a></li>
                        </ul>
                    </div>
                </div>
                <div class="col-md-6">
                    <input type="search" class="form-control" placeholder="搜尋商品...">
                </div>
            </div>
            <!-- 購物列表 -->
            <div class="row" id="shopping-list">
                <?php
                  $products = [
                    ["name" => "Product 1", "image" => "https://via.placeholder.com/150", "price" => "$1.99"],
                      ["name" => "Product 2", "image" => "https://via.placeholder.com/150", "price" => "$2.99"],
                      ["name" => "Product 3", "image" => "https://via.placeholder.com/150", "price" => "$33.99"],
                      ["name" => "Product 4", "image" => "https://via.placeholder.com/150", "price" => "$44.52"],
                      ["name" => "Product 5", "image" => "https://via.placeholder.com/150", "price" => "$52"],
                      ["name" => "Product 6", "image" => "https://via.placeholder.com/150", "price" => "$66"],
                      ["name" => "Product 7", "image" => "https://via.placeholder.com/150", "price" => "$77"],
                  ];
                  foreach ($products as $product)
                  {
                      echo "<div class=\"col-md-2\">
                              <a href=\"product.html\" class=\"card-link text-decoration-none text-primary\">
                                  <div class=\"card mb-3\">
                                      <img src=\"{$product['image']}\" class=\"card-img-top\" alt=\"Product Image\">
                                      <div class=\"card-body\">
                                          <h5 class=\"card-title text-Nmain\">{$product['name']}</h5>
                                          <p class=\"card-text fw-bold text-orange\">{$product['price']}</p>
                                      </div>
                              </a>
                              <button class=\"btn cart\" aria-label=\"購物車圖示\"><i class=\"bi bi-cart\"></i></button>
                            </div>
                          </div>";
                  }
                ?>
            </div>
        </div>
    </main>
    <footer class="bottom d-flex justify-content-between align-items-center py-3">
        <div class="container d-flex justify-content-between">
            <div class="col-md-4 d-flex align-items-center ">
                <span class="mb-3 mt-3">Copyright © 2024 閱緣書坊 All right reserved</span>
            </div>
            <form>
                <div class="input-group mt-2">
                    <input type="email " class="sub form-control" placeholder="訂閱電子報">
                    <button class="btn btn-primary" type="submit">訂閱</button>
                </div>
            </form>
            <ul class="nav col-md-4 justify-content-end mt-3">
                <li class="ms-3"><a class="text-body-secondary" href="#"><i
                            class='bx bxl-facebook-circle footerIcon'></i></a>
                <li class="ms-3"><a class="text-body-secondary" href="#"><i class='bx bxl-instagram footerIcon'></i></a>
                <li class="ms-3"><a class="text-body-secondary" href="#"><i class='bx bxl-youtube footerIcon'></i></a>
            </ul>
        </div>
    </footer>
</body>
<!-- Bootstrap js連結 -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
<!--自定義js連結 -->
<script src="js/bookshop.js"></script>

</html>