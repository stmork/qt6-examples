//
//  SPDX-License-Identifier: MIT
//  SPDX-FileCopyrightText: Copyright (C) 2008-2025 Steffen A. Mork
//

pipeline
{
    agent
    {
        label 'QT'
    }

    stages
    {
        stage ('CMake')
        {
           steps
           {
              sh 'cmake -B build'
           }
        }
        stage ('Build')
        {
            steps
            {
                sh 'make -C build -j `nproc`'
            }
        }

        stage ('CppCheck')
        {
            steps
            {
                sh 'make -C build cppcheck'
                publishCppcheck pattern: 'cppcheck.xml'
            }
        }
    }
}
