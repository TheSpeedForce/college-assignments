<?php
require_once "../common/dbFetch.php";
require_once "../common/dbconnect.php";

if (session_status() === PHP_SESSION_NONE) {
    session_start();
}
$username = $_SESSION['username'];
$first_initial = $_SESSION['first_initial'];

$edit = isset($_POST['edit']) ? $_POST['edit'] : -1;

if (isset($_POST['submit']) && $_POST['submit'] != "") {
    $loginId = fetch($con, "SELECT loginInfoId FROM supervisor WHERE id = {$_POST['id']}")[0];
    $query = "UPDATE loginInfo SET userName = '{$_POST['userName']}', email = '{$_POST['email']}', fName = '{$_POST['fName']}', lName = '{$_POST['lName']}' WHERE id = {$loginId['loginInfoId']}";
    fetch($con, $query);
}

if (isset($_POST['addNew'])) {
    $query = "INSERT INTO loginInfo (username, email, fName, lName, pwdHash) VALUES ('{$_POST['addUserName']}', '{$_POST['addEmail']}', '{$_POST['addFName']}', '{$_POST['addLName']}', '{$_POST['addPass']}')";
    fetch($con, $query);

    $query2 = "SELECT id FROM loginInfo WHERE username = '{$_POST['addUserName']}'";
    $supId = fetch($con, $query2)[0];

    fetch($con, "INSERT INTO supervisor (loginInfoId, roleId) VALUES ({$supId['id']}, 1)");
}
$supervisors = fetch($con, "SELECT supervisor.id, loginInfo.username, loginInfo.email, loginInfo.fName, loginInfo.lName FROM supervisor INNER JOIN loginInfo ON loginInfo.id = supervisor.loginInfoId WHERE roleId = 1");

?>

<!DOCTYPE html>
<html lang="en-US">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Admin Menu</title>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link media="all" rel="stylesheet" href="../iudesign/css/rivet.min.css">
    <script src="../iudesign/js/rivet.min.js"></script>
    <!-- Change Title here for each module !-->
    <title>Admin Menu</title>
</head>

<body>
<header class="rvt-header" role="banner">
    <a class="rvt-skip-link" href="#main-content">Skip to content</a>
    <!-- Trident -->
    <div class="rvt-header__trident">
        <svg class="rvt-header__trident-logo" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 41 48" aria-hidden="true">
            <title id="iu-logo">Indiana University Logo</title>
            <rect width="41" height="48" fill="#900"/>
            <polygon points="24.59 12.64 24.59 14.98 26.34 14.98 26.34 27.78 22.84 27.78 22.84 10.9 24.59 10.9 24.59 8.57 16.41 8.57 16.41 10.9 18.16 10.9 18.16 27.78 14.66 27.78 14.66 14.98 16.41 14.98 16.41 12.64 8.22 12.64 8.22 14.98 9.97 14.98 9.97 30.03 12.77 33.02 18.16 33.02 18.16 36.52 16.41 36.52 16.41 39.43 24.59 39.43 24.59 36.52 22.84 36.52 22.84 33.02 28 33.02 31.01 30.03 31.01 14.98 32.78 14.98 32.78 12.64 24.59 12.64" fill="#fff"/>
        </svg>
    </div>
    <!-- App title -->
    <span class="rvt-header__title">
        <a href="#" class = "inactiveLink">Admin Menu</a>
    </span>
    <!-- Wrapper for header interactive elements -->
    <div class="rvt-header__controls">
        <!-- Main inline nav element -->
        <nav class="rvt-header__main-nav" role="navigation">
            <ul>
                <!-- First Navigation !-->
                <li>
                    <a href="../admin/adminMenu.php">Dashboard</a>
                </li>
                <!-- First Navigation !-->
                <li>
                    <a href="../admin/uploadDatasheet.php">Upload/View Datasheet</a>
                </li>

                <!-- Drop down Navigation !-->
                <li>
                    <div class="rvt-dropdown">
                        <button type="button" class="rvt-dropdown__toggle" data-dropdown-toggle="dropdown-2" aria-haspopup="true" aria-expanded="false">
                            <span class="rvt-dropdown__toggle-text"><a aria-current = "page">Add New / Edit Site Supervisor</a></span>
                            <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                <title>Dropdown icon</title>
                                <path fill="currentColor" d="M8,12.46a2,2,0,0,1-1.52-.7L1.24,5.65a1,1,0,1,1,1.52-1.3L8,10.46l5.24-6.11a1,1,0,0,1,1.52,1.3L9.52,11.76A2,2,0,0,1,8,12.46Z"
                                />
                            </svg>
                        </button>
                        <div class="rvt-dropdown__menu" id="dropdown-2" aria-hidden="true">
                            <a href="..\add_edit\editAdmin.php">Admin</a>
                            <a href="..\add_edit\editStudentLanding.php">Student</a>
                            <a href="..\add_edit\editSiteSupervisor.php">Site Supervisor</a>
                            <a href="..\add_edit\editFacultySupervisor.php">Faculty Supervisor</a>
                            <a href="..\add_edit\editSite.php">Site</a>
                            <a href="..\add_edit\editSemester.php">Semester</a>
                            <a href="..\add_edit\editCourse.php">Internship Course</a>
                            <a href="#">Site Preference</a>
                            
                        </div>
                    </div>
                </li>
                <!-- Drop down Navigation !-->
                <li>
                    <div class="rvt-dropdown">
                        <button type="button" class="rvt-dropdown__toggle" data-dropdown-toggle="dropdown-3" aria-haspopup="true" aria-expanded="false">
                            <span class="rvt-dropdown__toggle-text">Account Settings</span>
                            <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                <title>Dropdown icon</title>
                                <path fill="currentColor" d="M8,12.46a2,2,0,0,1-1.52-.7L1.24,5.65a1,1,0,1,1,1.52-1.3L8,10.46l5.24-6.11a1,1,0,0,1,1.52,1.3L9.52,11.76A2,2,0,0,1,8,12.46Z"
                                />
                            </svg>
                        </button>
                        <div class="rvt-dropdown__menu" id="dropdown-3" aria-hidden="true">
                            <a href="../common/editProfile.php">Edit Profile</a>
                            <a href="../common/changePassword.php">Change Password</a>
                        </div>
                    </div>
                </li>
                
                
            </ul>
        </nav>
        <!-- ID menu w/ dropdown -->
        <div class="rvt-header-id">
            <div href="#0" class="rvt-header-id__profile">

                <!-- change these to your username for now !-->
                <span class="rvt-header-id__avatar" aria-hidden="true"><?php print $first_initial ?></span>
                <span class="rvt-header-id__user"><?php print $username ?></span>
            </div>
            <a href="../common/logout.php" class="rvt-header-id__log-out">Log out</a>
        </div>
       
    </div>
     
</header>
    <div class="container">
        <form action="editSiteSupervisor.php" method="post">
            <main>
                <h1>Edit Site Supervisors</h1>
                <h3>Site Supervisors</h3>
                <table class="rvt-table-stripes">
                    <thead>
                        <tr>
                            <th scope="col">Id</th>
                            <th scope="col">Username</th>
                            <th scope="col">Email</th>
                            <th scope="col">First Name</th>
                            <th scope="col">Last Name</th>
                            <th scope="col">Students</th>
                            <th class='addRow' hidden='true'>Password</td>
                            <th class='addRow' hidden='true'>Password Confirm</td>
                            <th></th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                        foreach ($supervisors as $sup) {
                            if ($edit == -1) {
                                echo "
                                <tr>
                                    <td scope='row'>{$sup['id']}</td>
                                    <td scope='row'>{$sup['username']}</td>
                                    <td scope='row'>{$sup['email']}</td>
                                    <td scope='row'>{$sup['fName']}</td>
                                    <td scope='row'>{$sup['lName']}</td>
                                    <td scope='row'>
                                        <select name='students'>";
                                echo $sup['id'];
                                $students = fetch($con, "SELECT student.id, fName, lName, siteSupervisorId FROM `student` INNER JOIN loginInfo ON loginInfo.id = student.id WHERE student.siteSupervisorId = {$sup['id']}");
                                foreach ($students as $student) {
                                    echo "<option value='{$student['id']}'>{$student['fName']} {$student['lName']}</option>";
                                }
                                echo "</select></td>";
                                echo "<td class='addRow' hidden='true'></td>
                                    <td class='addRow' hidden='true'></td>
                                    <td scope='row'>
                                        <form action='editSiteSupervisor.php' method='post'>
                                            <button class='rvt-button' name='edit' value='{$sup['id']}'>Edit</button>
                                        </form>
                                    </td>
                                </tr>
                                ";
                            } else {
                                echo "
                                <tr>
                                    <form action='editSiteSupervisor.php', method='post'>
                                        <td scope='row'>
                                            <input type='text' name='id' value='{$sup['id']}' readonly>
                                        </td>
                                        <td scope='row'>
                                            <input type='text' name='userName' value='{$sup['username']}'>
                                        </td>
                                        <td scope='row'>
                                            <input type='text' name='email' value='{$sup['email']}'>
                                        </td>
                                        <td scope='row'>
                                            <input type='text' name='fName' value='{$sup['fName']}'>
                                        </td>
                                        <td scope='row'>
                                            <input type='text' name='lName' value='{$sup['lName']}'>
                                        </td>
                                        <td scope='row'>
                                        <select name='students'>";
                                echo $sup['id'];
                                $students = fetch($con, "SELECT student.id, fName, lName, siteSupervisorId FROM `student` INNER JOIN loginInfo ON loginInfo.id = student.id WHERE student.siteSupervisorId = {$sup['id']}");
                                foreach ($students as $student) {
                                    echo "<option value='{$student['id']}'>{$student['fName']} {$student['lName']}</option>";
                                }
                                echo "</select></td>
                                        <td class='addRow' hidden='true'></td>
                                        <td class='addRow' hidden='true'></td>
                                        <td scope='row'>
                                            <form action='editSiteSupervisor.php' method='post'>
                                                <button class='rvt-button' name='submit' value='{$sup['id']}'>Submit</button>
                                            </form>
                                        </td>
                                    </form>
                                </tr>
                                ";
                            }
                        }
                        ?>
                        <tr class='addRow' hidden='true'>
                            <form action='editSiteSupervisor.php' method='post'>
                                <td scope='row'></td>
                                <td scope='row'>
                                    <input type='text' name='addUserName' value='User Name'>
                                </td>
                                <td scope='row'>
                                    <input type='text' name='addEmail' value='Email'>
                                </td>
                                <td scope='row'>
                                    <input type='text' name='addFName' value='First'>
                                </td>
                                <td scope='row'>
                                    <input type='text' name='addLName' value='Last'>
                                </td>
                                <td>
                                    <select data-placeholder="Add Students..." multiple class="select" name="addStudents" tabindex="4">
                                        <option value=""></option>
                                        <?php
                                        $studentsAdding = fetch($con, "SELECT student.id, fName, lName FROM student INNER JOIN loginInfo ON loginInfo.id=student.id");
                                        foreach ($studentsAdding as $student) {
                                            echo "<option>{$student['fName']} {$student['lName']}</option>";
                                        }
                                        ?>
                                    </select>
                                </td>
                                <td scope='row'>
                                    <input type='password' name='addPass'>
                                </td>
                                <td scope='row'>
                                    <input type='password' name='addPassConf'>
                                </td>
                                <td scope='row'>
                                    <form action='editSiteSupervisor.php' method='post'>
                                        <button class='rvt-button' name='addNew' value=''>Add</button>
                                    </form>
                                </td>

                            </form>
                        </tr>
                        <tr>
                            <td scope='row'>
                                <button type='button' onclick='add()' class='rvt-button'>Add New</button>
                            </td>
                            <td></td>
                            <td></td>
                            <td></td>
                            <td></td>
                            <td></td>
                            <td class='addRow' hidden='true'></td>
                            <td class='addRow' hidden='true'></td>
                        </tr>
                    </tbody>
                </table>
                <form>
    </div>
    <script>
        function add() {
            addRow = document.getElementsByClassName('addRow');
            for (i = 0; i < addRow.length; i++) {
                addRow[i].hidden = false;
            }
        }
    </script>
    <script>
        $(function() {
            $(".chosen-select").chosen();
        });
    </script>
<?php include "../common/footer.php" ?>